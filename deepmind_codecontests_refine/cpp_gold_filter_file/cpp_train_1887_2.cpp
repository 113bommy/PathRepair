#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  vector<int> q;
  q.push_back(1);
  int k = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1])
      q[k]++;
    else {
      k++;
      q.push_back(1);
    }
  }
  sort(q.begin(), q.end());
  int ans = 0;
  for (int i = 0; i < q.size(); i++)
    for (int fd = 1; fd <= q[i]; fd++) {
      int j = i;
      int tans = 0;
      int tf = fd;
      while (j < q.size() && q[j] >= tf) {
        tans += tf;
        tf *= 2;
        j++;
      }
      ans = max(ans, tans);
    }
  cout << ans;
  cin >> ans;
}
