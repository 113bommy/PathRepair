#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long n;
  cin >> n;
  vector<vector<long long>> adjList(n + 1);
  vector<pair<long long, long long>> edges;
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    edges.emplace_back(a, b);
  }
  long long flag = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (adjList[i].size() >= 3) {
      flag = i;
      break;
    }
  }
  if (flag == 0) {
    for (long long i = 0; i < n - 1; i++) {
      cout << i << "\n";
    }
  } else {
    long long count1 = 0;
    long long count2 = n - 2;
    for (long long i = 0; i < edges.size(); i++) {
      pair<long long, long long> edge = edges[i];
      if (edge.first == flag || edge.second == flag) {
        cout << count1 << "\n";
        count1++;
      } else {
        cout << count2 << "\n";
        count2--;
      }
    }
    assert(count1 - count2 == 1);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testcase();
}
