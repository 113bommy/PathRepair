#include <bits/stdc++.h>
using namespace std;
long long ans = (1 << 30), n, m, arr[51][3];
string s;
int nearD() {
  int i, st = 0;
  bool b = false;
  for (int i = 0, j = s.size(); i < s.size(); i++, j--, st++)
    if ((s[i] >= '0' && s[i] <= '9') ||
        (j != n && s[j] >= '0' && s[j] <= '9')) {
      b = true;
      break;
    }
  if (!b) return (1 << 30);
  return st;
}
int nearC() {
  int i, st = 0;
  bool b = false;
  for (int i = 0, j = s.size(); i < s.size(); i++, j--, st++)
    if ((s[i] >= 'a' && s[i] <= 'z') ||
        (j != n && s[j] >= 'a' && s[j] <= 'z')) {
      b = true;
      break;
    }
  if (!b) return (1 << 30);
  return st;
}
int nearS() {
  int i, st = 0;
  bool b = false;
  for (int i = 0, j = s.size(); i < s.size(); i++, j--, st++)
    if (s[i] == '&' || s[i] == '#' || s[i] == '*' ||
        (j != n && s[j] == '*' || s[j] == '&' || s[j] == '#')) {
      b = true;
      break;
    }
  if (!b) return (1 << 30);
  return st;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    arr[i][0] = nearD();
    arr[i][1] = nearC();
    arr[i][2] = nearS();
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (i != j && j != k && i != k)
          ans = min(ans,
                    min(arr[i][0] + arr[j][1] + arr[k][2],
                        min(arr[i][0] + arr[j][2] + arr[k][1],
                            min(arr[i][1] + arr[j][2] + arr[k][0],
                                min(arr[i][1] + arr[j][0] + arr[k][2],
                                    min(arr[i][2] + arr[j][0] + arr[k][1],
                                        arr[i][2] + arr[j][1] + arr[k][0]))))));
  cout << ans << endl;
  return 0;
}
