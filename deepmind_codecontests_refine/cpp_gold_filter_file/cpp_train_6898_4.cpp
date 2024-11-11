#include <bits/stdc++.h>
using namespace std;
int t;
int a[100];
string s;
int main() {
  cin >> t;
  for (int zz = 0; zz < t; zz++) {
    for (int i = 0; i < 100; i++) a[i] = 0;
    cin >> s;
    s = "0" + s + "0";
    int indx = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '1')
        cnt++;
      else {
        if (cnt) a[indx++] = cnt;
        cnt = 0;
      }
    for (int i = 0; i < 99; i++)
      for (int j = 0; j < 99; j++)
        if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
    int ans = 0;
    for (int i = 0; i < 100; i = i + 2) ans += a[i];
    cout << ans << endl;
  }
}
