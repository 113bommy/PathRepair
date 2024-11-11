#include <bits/stdc++.h>
using namespace std;
const long long MUCH = 1000000;
const long long INF = 500000000000ll;
template <class t>
ostream &operator<<(ostream &tout, const vector<t> &s) {
  tout << '[';
  for (long long i = 0; i < s.size(); i++)
    if (i + 1 == s.size())
      tout << s[i];
    else
      tout << s[i] << ',';
  tout << ']';
  return (tout);
}
long long *_distance;
struct MinCostFlowCmp {
  bool operator()(long long a, long long b) {
    if (_distance[a] != _distance[b]) return (_distance[a] < _distance[b]);
    return (a < b);
  }
};
vector<long long> c, f, cost, potential, l, r;
class MinCostFlow {
 public:
  long long n;
  bool init;
  vector<vector<long long> > next, prev;
  long long *distance;
  long long _cost(long long s) {
    return (cost[s] + potential[r[s]] - potential[l[s]]);
  }

 public:
  MinCostFlow(long long n) {
    this->n = n;
    init = false;
    next.clear();
    prev.clear();
    c.clear();
    f.clear();
    cost.clear();
    l.clear();
    r.clear();
    next.resize(n + 1);
    prev.resize(n + 1);
    potential.resize(n + 1);
    distance = new long long[n + 1];
  }
  void push_back(long long left, long long right, long long C, long long Cost) {
    if (C == 0) return;
    c.push_back(C);
    f.push_back(0);
    cost.push_back(Cost);
    next[left].push_back(c.size() - 1);
    prev[right].push_back(c.size() - 1);
    l.push_back(left);
    r.push_back(right);
  }
  long long minCostFlow(long long start, long long end, long long Max) {
    if (!init) {
      fill(distance + 1, distance + n + 1, INF);
      distance[start] = 0;
      for (long long count = 1; count <= n; count++)
        for (long long i = 0; i < l.size(); i++)
          distance[r[i]] = min(distance[r[i]], distance[l[i]] + cost[i]);
      init = true;
    }
    long long ans = 0;
    while (Max) {
      vector<bool> mark(n + 1);
      for (long long i = 0; i < potential.size(); i++)
        potential[i] -= distance[i];
      fill(distance + 1, distance + n + 1, INF);
      distance[start] = 0;
      _distance = distance;
      set<long long, MinCostFlowCmp> Set;
      for (long long i = 1; i <= n; i++) Set.insert(i);
      vector<long long> last(n + 1);
      vector<bool> is_r(n + 1);
      while (Set.size()) {
        long long x = *Set.begin();
        Set.erase(x);
        if (distance[x] == INF) break;
        for (long long i = 0; i < next[x].size(); i++)
          if (c[next[x][i]] > f[next[x][i]])
            if (distance[r[next[x][i]]] > distance[x] + _cost(next[x][i])) {
              Set.erase(r[next[x][i]]);
              distance[r[next[x][i]]] = distance[x] + _cost(next[x][i]);
              last[r[next[x][i]]] = next[x][i];
              is_r[r[next[x][i]]] = true;
              Set.insert(r[next[x][i]]);
            }
        for (long long i = 0; i < prev[x].size(); i++)
          if (f[prev[x][i]])
            if (distance[l[prev[x][i]]] > distance[x] - _cost(prev[x][i])) {
              Set.erase(l[prev[x][i]]);
              distance[l[prev[x][i]]] = distance[x] - _cost(prev[x][i]);
              last[l[prev[x][i]]] = prev[x][i];
              is_r[l[prev[x][i]]] = false;
              Set.insert(l[prev[x][i]]);
            }
      }
      if (distance[end] == INF) break;
      vector<long long> edges, zarib;
      long long temp = end;
      while (temp != start) {
        edges.push_back(last[temp]);
        if (is_r[temp])
          zarib.push_back(1);
        else
          zarib.push_back(-1);
        if (is_r[temp])
          temp = l[last[temp]];
        else
          temp = r[last[temp]];
      }
      long long Min = Max;
      for (long long i = 0; i < edges.size(); i++)
        if (zarib[i] == 1)
          Min = min(Min, c[edges[i]] - f[edges[i]]);
        else
          Min = min(Min, f[edges[i]]);
      Max -= Min;
      for (long long i = 0; i < edges.size(); i++) {
        ans += cost[edges[i]] * zarib[i] * Min;
        f[edges[i]] += zarib[i] * Min;
      }
    }
    return (ans);
  }
  long long minCostFlow(long long start, long long end) {
    return (minCostFlow(start, end, INF));
  }
};
long long gt(long long s) {
  long long ans = 0;
  while (s) {
    ans += s % 2;
    s /= 2;
  }
  return (ans);
}
template <class T>
string to_string(T s) {
  stringstream tin;
  tin << s;
  string res;
  getline(tin, res);
  return (res);
}
long long n, m;
int main() {
  cin >> n >> m;
  vector<long long> all;
  for (long long i = 1; i <= n; i++) {
    long long temp;
    cin >> temp;
    all.push_back(temp);
  }
  MinCostFlow mai(2 * n + 2);
  for (long long i = 1; i <= n; i++) mai.push_back(i, i + n, 1, -MUCH);
  for (long long i = 1; i <= n; i++) {
    mai.push_back(2 * n + 1, i, 1, gt(all[i - 1]));
    mai.push_back(i + n, 2 * n + 2, 1, 0);
  }
  for (long long i = 0; i < all.size(); i++)
    for (long long j = i + 1; j < all.size(); j++)
      if (all[i] == all[j])
        mai.push_back(i + n + 1, j + 1, 1, 0);
      else
        mai.push_back(i + n + 1, j + 1, 1, gt(all[j]));
  mai.push_back(2 * n + 1, 2 * n + 2, m, 0);
  long long res = mai.minCostFlow(2 * n + 1, 2 * n + 2, m) + MUCH * n;
  vector<long long> last(n + 1);
  vector<long long> who(n + 1);
  long long count = 0;
  for (long long i = 0; i < f.size(); i++)
    if (f[i]) {
      if (l[i] == 2 * n + 1) {
        count++;
        who[r[i]] = count;
        last[r[i]] = -1;
      } else if (r[i] <= n)
        last[r[i]] = l[i] - n;
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      if (last[i] != -1) who[i] = who[last[i]];
  vector<string> result;
  for (long long i = 1; i <= n; i++) {
    if (last[i] != -1 && (last[i] >= i || last[i] < 1))
      while (true)
        ;
    if (who[i] < 1 || who[i] > m)
      while (true)
        ;
  }
  for (long long i = 1; i <= n; i++) {
    if (who[i] == -1 || all[last[i] - 1] != all[i - 1])
      result.push_back(char(who[i] + 'a' - 1) + string("=") +
                       to_string(all[i - 1]));
    result.push_back(string("print(") + char(who[i] + 'a' - 1) + string(")"));
  }
  cout << result.size() << ' ' << res << endl;
  for (long long i = 0; i < result.size(); i++) cout << result[i] << endl;
}
