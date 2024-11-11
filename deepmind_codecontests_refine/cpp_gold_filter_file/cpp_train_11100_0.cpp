#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (k >= n) {
    cout << n << endl;
    return 0;
  }
  int cnt;
  int i, j;
  if (v[0] < v[1]) {
    i = 1;
    j = 2;
    cnt = 1;
  } else {
    i = 0;
    j = 1;
    cnt = 0;
  }
  if (v[0] == n) {
    cout << n << endl;
    return 0;
  }
  while (j < n && cnt <= k) {
    if (v[j] < v[i]) {
      cnt++;
      j++;
      if (cnt == k) {
        cout << v[i] << endl;
        return 0;
      }
    } else {
      i = j;
      j = i + 1;
      if (v[i] == n) {
        cout << n << endl;
        return 0;
      }
      cnt = 1;
    }
  }
  cout << n << endl;
  return 0;
}
