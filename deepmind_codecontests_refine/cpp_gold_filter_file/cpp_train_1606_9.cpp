#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, cnt;
  cin >> n;
  vector<long long int> a(n);
  vector<long long int> b(n);
  long long int c = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<long long int> ans1(n, 0);
  vector<long long int> ans2(n, 0);
  i = 0, j = 0, cnt = n;
  while (i < n && j < n) {
    if (a[i] >= b[j]) {
      ans2[j] = 1;
      j++;
      cnt--;
    }
    if (cnt == 0) break;
    if (a[i] <= b[j]) {
      ans1[i] = 1;
      i++;
      cnt--;
    }
    if (cnt == 0) break;
  }
  long long int k = n / 2;
  for (i = 0; i < k; i++) {
    ans1[i] = 1;
  }
  for (i = 0; i < k; i++) {
    ans2[i] = 1;
  }
  if (n % 2 == 1) {
    if (a[k] > b[k])
      ans2[k] = 1;
    else
      ans1[k] = 1;
  }
  for (i = 0; i < n; i++) cout << ans1[i];
  cout << endl;
  for (i = 0; i < n; i++) cout << ans2[i];
}
