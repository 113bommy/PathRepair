#include <bits/stdc++.h>
using namespace std;
int n;
int tarjan_count = 0;
int tarjan_nontrivial = 0;
stack<int> tarjan_stack;
vector<bool> tarjan_onstack;
vector<int> bounds;
vector<int> tarjan_component;
vector<int> tarjan_index;
vector<int> tarjan_lowlink;
vector<pair<int, int> > ab;
void ReadData() {
  int m;
  scanf("%d%d", &n, &m);
  ab.resize(m);
  for (int i = 0; i < ab.size(); ++i) {
    scanf("%d%d", &ab[i].first, &ab[i].second);
    --ab[i].first;
    --ab[i].second;
  }
}
void PreprocessData() {
  sort(ab.begin(), ab.end());
  {
    bounds.clear();
    int i = 0;
    while (i < ab.size()) {
      while (ab[i].first >= bounds.size()) bounds.push_back(i);
      ++i;
    }
    while (n >= bounds.size()) bounds.push_back(ab.size());
  }
}
void StrongConnect(const int v) {
  tarjan_index[v] = tarjan_count;
  tarjan_lowlink[v] = tarjan_count;
  ++tarjan_count;
  tarjan_stack.push(v);
  tarjan_onstack[v] = true;
  for (int i = bounds[v]; i < bounds[v + 1]; ++i) {
    const int w = ab[i].second;
    if (tarjan_index[w] == -1) {
      StrongConnect(w);
      tarjan_lowlink[v] = min(tarjan_lowlink[v], tarjan_lowlink[w]);
    } else if (tarjan_onstack[w]) {
      tarjan_lowlink[v] = min(tarjan_lowlink[v], tarjan_index[w]);
    }
  }
  if (tarjan_lowlink[v] == tarjan_index[v]) {
    vector<int> component;
    while (true) {
      const int w = tarjan_stack.top();
      tarjan_stack.pop();
      tarjan_onstack[w] = false;
      component.push_back(w);
      if (w == v) break;
    }
    if (component.size() > 1) {
      ++tarjan_nontrivial;
      tarjan_component = component;
    }
  }
}
void StronglyConnectedComponents() {
  tarjan_index.resize(n, -1);
  tarjan_lowlink.resize(n, 0);
  tarjan_onstack.resize(n, false);
  for (int i = 0; i < n; ++i)
    if (tarjan_index[i] == -1) StrongConnect(i);
}
int NontrivialSccCount() { return tarjan_nontrivial; }
int component_size = 0;
int remaining_vertex = -1;
void CopyAndReduceComponent() {
  sort(tarjan_component.begin(), tarjan_component.end());
  vector<set<int> > forward(n), back(n);
  vector<pair<int, int> > edges;
  int j = 0;
  for (int i = 0; i < ab.size(); ++i) {
    const int a = ab[i].first;
    const int b = ab[i].second;
    if (binary_search(tarjan_component.begin(), tarjan_component.end(), a) &&
        binary_search(tarjan_component.begin(), tarjan_component.end(), b)) {
      forward[a].insert(b);
      back[b].insert(a);
      ab[j++] = make_pair(a, b);
    }
  }
  ab.resize(j);
  set<int> forward_one, back_one;
  vector<int> forward_decode(n), back_decode(n), forward_encode(n),
      back_encode(n);
  for (int i = 0; i < n; ++i) {
    forward_decode[i] = i;
    back_decode[i] = i;
    forward_encode[i] = i;
    back_encode[i] = i;
    if (forward[i].size() == 1) {
      forward_one.insert(i);
    }
    if (back[i].size() == 1) {
      back_one.insert(i);
    }
  }
  while (!forward_one.empty() || !back_one.empty()) {
    if (!forward_one.empty()) {
      const int a = *forward_one.begin();
      forward_one.erase(a);
      const int b = forward_decode[*forward[a].begin()];
      if (b != a) {
        forward[a].clear();
        back[b].erase(back_encode[a]);
        if (back[a].size() > back[b].size()) {
          back[a].swap(back[b]);
          swap(forward_encode[a], forward_encode[b]);
          forward_decode[forward_encode[a]] = a;
          forward_decode[forward_encode[b]] = b;
        }
        for (set<int>::const_iterator i = back[a].begin(); i != back[a].end();
             ++i) {
          const int aa = back_decode[*i];
          forward[aa].erase(forward_encode[a]);
          if (back[b].find(*i) == back[b].end()) {
            back[b].insert(*i);
            forward[aa].insert(forward_encode[b]);
          } else {
            if (forward[aa].size() == 1)
              forward_one.insert(aa);
            else
              forward_one.erase(aa);
          }
        }
        back[a].clear();
        back_one.erase(a);
        if (back[b].size() == 1)
          back_one.insert(b);
        else
          back_one.erase(b);
      }
    }
    if (!back_one.empty()) {
      const int a = *back_one.begin();
      back_one.erase(a);
      const int b = back_decode[*back[a].begin()];
      if (b != a) {
        back[a].clear();
        forward[b].erase(forward_encode[a]);
        if (forward[a].size() > forward[b].size()) {
          forward[a].swap(forward[b]);
          swap(back_encode[a], back_encode[b]);
          back_decode[back_encode[a]] = a;
          back_decode[back_encode[b]] = b;
        }
        for (set<int>::const_iterator i = forward[a].begin();
             i != forward[a].end(); ++i) {
          const int aa = forward_decode[*i];
          back[aa].erase(back_encode[a]);
          if (forward[b].find(*i) == forward[b].end()) {
            forward[b].insert(*i);
            back[aa].insert(back_encode[b]);
          } else {
            if (back[aa].size() == 1)
              back_one.insert(aa);
            else
              back_one.erase(aa);
          }
        }
        forward[a].clear();
        forward_one.erase(a);
        if (forward[b].size() == 1)
          forward_one.insert(b);
        else
          forward_one.erase(b);
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (!forward[i].empty() || !back[i].empty()) {
      ++component_size;
      remaining_vertex = i;
    }
}
int ReducedComponentSize() { return component_size; }
int GetRemainingVertexNumber() { return remaining_vertex; }
void ConvertComponentToDag(const int a) {
  for (int i = 0; i < ab.size(); ++i)
    if (ab[i].second == a) ab[i].second = n;
  ++n;
  PreprocessData();
}
vector<int> articulation;
void ComputeArticulationPoints() {
  vector<int> active(n, 0);
  vector<int> in_degree(n, 0);
  vector<int> out_degree(n, 0);
  for (int i = 0; i < ab.size(); ++i) {
    ++out_degree[ab[i].first];
    ++in_degree[ab[i].second];
  }
  stack<int> ready;
  for (int i = 0; i < n; ++i)
    if (in_degree[i] || out_degree[i])
      if (active[i] == in_degree[i]) ready.push(i);
  int in_flight = 0;
  while (!ready.empty()) {
    const int a = ready.top();
    ready.pop();
    in_flight -= in_degree[a];
    if (in_flight == 0) articulation.push_back(a);
    for (int i = bounds[a]; i < bounds[a + 1]; ++i) {
      ++in_flight;
      const int b = ab[i].second;
      if (in_degree[b] || out_degree[b])
        if (++active[b] == in_degree[b]) ready.push(b);
    }
  }
}
void PrintArticulationPoints() { printf("%d\n", articulation.front() + 1); }
int main() {
  ReadData();
  PreprocessData();
  StronglyConnectedComponents();
  if (NontrivialSccCount() == 0) {
    printf("-1\n");
  } else if (NontrivialSccCount() >= 2) {
    printf("-1\n");
  } else {
    CopyAndReduceComponent();
    if (ReducedComponentSize() > 1) {
      printf("-1\n");
    } else {
      ConvertComponentToDag(GetRemainingVertexNumber());
      ComputeArticulationPoints();
      PrintArticulationPoints();
    }
  }
  return 0;
}
