#include <bits/stdc++.h>
using namespace std;
vector<int> cc[100000];
int num[100000];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  for (int j = 0; j < n; cin >> num[j++])
    ;
  sort(num, num + n);
  for (int j = 0; j < m; cc[j++].clear())
    ;
  cc[0].push_back(0);
  for (int j = 1; j < n; j++) cc[(num[j] - num[0]) % m].push_back(j);
  for (int j = 0; j < m; j++) {
    if (cc[j].size() >= k) {
      cout << "Yes" << endl;
      for (int i = 0; i < k; i++) {
        cout << num[cc[j][i]] << " ";
      }
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
