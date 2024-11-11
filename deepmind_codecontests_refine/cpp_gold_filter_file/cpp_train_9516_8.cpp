#include <bits/stdc++.h>
using namespace std;
string Y = "YES\n";
string N = "NO\n";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int mini = INT_MAX;
  int res = 0;
  vector<long long> vi;
  vector<long long> v;
  for (int i = 0; i < 9; i++) {
    long long q;
    cin >> q;
    vi.push_back(q);
    if (q <= mini) {
      mini = q;
      res = i + 1;
    }
  }
  int flag = 0;
  while (n >= mini) {
    v.push_back(res);
    n -= mini;
    flag = 1;
  }
  int remain = n;
  if (flag == 0) {
    cout << "-1" << endl;
  } else {
    int i = 0;
    while (true) {
      int flag = 0;
      int k = 8;
      while (k > res - 1) {
        if ((mini + remain) >= vi[k]) {
          v[i] = k + 1;
          flag = 1;
          remain -= (vi[k] - mini);
          i++;
          break;
        }
        k -= 1;
      }
      if (flag == 0) {
        break;
      }
    }
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
  }
  return 0;
}
