#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 * 1000 + 7;
int a[MAX], n;
int num[2 * MAX];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 1; i < n; i++) a[i] -= a[0];
  a[0] = 0;
  if (a[n - 1] > MAX) goto end;
  cerr << "AA" << endl;
  for (int i = 0; i < n; i++) num[a[i]]++;
  for (int i = 1; i <= a[n - 1] - 1; i++)
    if (num[i] < 2) goto end;
  cerr << "BB" << endl;
  for (int i = 1; i < a[n - 1]; i++) num[i]--;
  for (int i = 1; i <= a[n - 1]; i++) {
    num[i] -= num[i - 1] - 1;
    if (num[i] < 1) goto end;
  }
  cerr << "CC" << endl;
  if (num[a[n - 1]] != 1) goto end;
  cout << "YES" << endl;
  goto ender;
end:
  cout << "NO" << endl;
ender:;
  return 0;
}
