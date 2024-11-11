#include <bits/stdc++.h>
using namespace std;
struct DawgNode {
  unordered_map<char, int> lnk;
  int len{0};
  int suf{0};
  int cnt{0};
  int in{0};
  unordered_set<int> revLnk;
  int out{0};
  int64_t total{0};
};
struct Dawg {
  vector<DawgNode> nodes;
  int siz;
  void build(const string& s) {
    nodes.resize(s.size() * 2);
    nodes[0].suf = -1;
    siz = 1;
    int last = 0;
    for (char c : s) {
      auto& newNode = nodes[siz++];
      newNode.len = nodes[last].len + 1;
      newNode.cnt = 1;
      int prev = last;
      last = siz - 1;
      while (prev != -1 && !nodes[prev].lnk.count(c)) {
        nodes[prev].lnk[c] = siz - 1;
        prev = nodes[prev].suf;
      }
      if (prev == -1) continue;
      int nx = nodes[prev].lnk[c];
      if (nodes[prev].len + 1 == nodes[nx].len) {
        newNode.suf = nx;
      } else {
        auto& clone = nodes[siz++];
        clone = nodes[nx];
        clone.len = nodes[prev].len + 1;
        clone.cnt = 0;
        while (prev != -1 && nodes[prev].lnk[c] == nx) {
          nodes[prev].lnk[c] = siz - 1;
          prev = nodes[prev].suf;
        }
        nodes[nx].suf = siz - 1;
        newNode.suf = siz - 1;
      }
    }
  }
  void fillCounts() {
    vector<int> q;
    q.reserve(nodes.size());
    for (int(i) = 0; (i) < (siz); ++(i))
      if (nodes[i].suf != -1) ++nodes[nodes[i].suf].in;
    for (int(i) = 0; (i) < (siz); ++(i))
      if (!nodes[i].in) q.push_back(i);
    int p = 0;
    while (p < q.size()) {
      int curr = q[p++];
      if (curr == 0) {
        nodes[0].cnt = 0;
        continue;
      }
      if (nodes[curr].suf == -1) continue;
      nodes[nodes[curr].suf].cnt += nodes[curr].cnt;
      if (--nodes[nodes[curr].suf].in == 0) q.push_back(nodes[curr].suf);
    }
  }
  void fillTotals() {
    vector<int> q;
    q.reserve(nodes.size());
    for (int(i) = 0; (i) < (siz); ++(i))
      for (auto pk : nodes[i].lnk) {
        nodes[pk.second].revLnk.insert(i);
      }
    for (int(i) = 0; (i) < (siz); ++(i))
      if ((nodes[i].out = nodes[i].lnk.size()) == 0) q.push_back(i);
    int p = 0;
    while (p < q.size()) {
      int curr = q[p++];
      nodes[curr].total += nodes[curr].cnt;
      for (auto prev : nodes[curr].revLnk) {
        nodes[prev].total += nodes[curr].total;
        if (--nodes[prev].out == 0) q.push_back(prev);
      }
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  string s;
  int k;
  cin >> s >> k;
  Dawg dawg;
  dawg.build(s);
  dawg.fillCounts();
  dawg.fillTotals();
  if (dawg.nodes[0].total < k) {
    cout << "No such line.\n";
    return 0;
  }
  string ans;
  int curr = 0;
  while (true) {
    if (dawg.nodes[curr].cnt >= k) {
      cout << ans << endl;
      return 0;
    } else {
      k -= dawg.nodes[curr].cnt;
    }
    for (int(i) = 0; (i) < (26); ++(i)) {
      if (dawg.nodes[curr].lnk.count('a' + i)) {
        int next = dawg.nodes[curr].lnk['a' + i];
        if (dawg.nodes[next].total >= k) {
          ans.push_back('a' + i);
          curr = next;
          break;
        } else {
          k -= dawg.nodes[next].total;
        }
      }
    }
  }
  return 0;
}
