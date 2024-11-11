#include <bits/stdc++.h>
using namespace std;
int cate[5];
int main() {
  long long n, i, cnt = 0;
  string a;
  ios_base::sync_with_stdio();
  cin >> a;
  n = a.size();
  if ((a[0] - '0') % 4 == 0) cnt++;
  for (i = 1; i < n; i++) {
    int nr = (a[i - 1] - '0') * 10 + (a[i] - '0');
    if (nr % 4 == 0) cnt += (i);
    if ((nr % 10) % 4 == 0) cnt++;
  }
  cout << cnt;
  return 0;
}
