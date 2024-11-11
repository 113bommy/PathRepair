#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::set;
using std::stack;
using std::string;
using std::stringstream;
using std::vector;
using namespace std;
vector<int> DFS(vector<vector<int> >& graph, int start) {
  stack<int> st;
  vector<int> visited(graph.size(), false);
  st.push(start);
  while (st.size() > 0) {
    int cur = st.top();
    st.pop();
    if (!visited[cur]) {
      visited[cur] = true;
      for (int i = 0; i < graph[cur].size(); ++i) {
        st.push(graph[cur][i]);
      }
    }
  }
  return visited;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int num_bit(long long v) {
  int ret = 0;
  while (v != 0) {
    ret += 1;
    v = v >> 1;
  }
  return ret;
}
int main() {
  std::cout.precision(10);
  int n;
  cin >> n;
  set<int> a_set;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    a_set.insert(v);
  }
  int res = 0;
  vector<int> a(a_set.begin(), a_set.end());
  for (int i = 0; i < a.size() - 1; ++i) {
    for (int k = 2;; ++k) {
      int val = a[i] * k;
      int idx = upper_bound(a.begin(), a.end(), val) - a.begin() - 1;
      res = max(res, a[idx] % a[i]);
      if (val >= a.back()) {
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
