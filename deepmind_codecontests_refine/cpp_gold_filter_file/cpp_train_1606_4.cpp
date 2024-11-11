#include <bits/stdc++.h>
using namespace std;
char s1[100005] = {'\0'}, s2[100005] = {'\0'};
int main() {
  int n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    s1[i] = s2[i] = '0';
  }
  a[n] = b[n] = 1000000002;
  int k = n / 2;
  for (int i = 0; i < k; i++) s1[i] = s2[i] = '1';
  int st1 = 0, st2 = 0;
  int last = n;
  while (last > 0) {
    if (a[st1] < b[st2])
      s1[st1++] = '1';
    else
      s2[st2++] = '1';
    last--;
  }
  st1 = st2 = k;
  last = n - 2 * k;
  while (last > 0) {
    if (a[st1] < b[st2])
      s1[st1++] = '1';
    else
      s2[st2++] = '1';
    last--;
  }
  cout << s1 << endl << s2;
  return 0;
}
