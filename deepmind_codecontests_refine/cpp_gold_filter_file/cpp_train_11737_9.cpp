#include <bits/stdc++.h>
using namespace std;
int a[150];
int b[150];
int n, k;
string s;
bool ok[400005], dem = -1;
int main() {
  cin.tie(NULL);
  cin >> n >> k;
  cin.ignore();
  cin >> s;
  for (int i = 1; i <= 50; i++) a[i] = 0;
  for (int i = 0; i < n; i++) {
    a[int(s[i]) - 96]++;
    b[int(s[i]) - 96]++;
  }
  bool o = true;
  int i = 1;
  while (k >= 1) {
    if (a[i] >= 1) {
      a[i]--;
      k--;
    } else
      i++;
  }
  int d = i;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (int(s[i]) - 96 > d)
      cout << s[i];
    else if (int(s[i]) - 96 == d && k + a[d] >= b[d])
      cout << s[i];
    else if (int(s[i]) - 96 == d)
      k++;
  }
  return 0;
}
