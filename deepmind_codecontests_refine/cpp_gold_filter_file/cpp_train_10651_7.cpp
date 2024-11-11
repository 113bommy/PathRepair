#include <bits/stdc++.h>
using namespace std;
int number(string s) {
  int h[10];
  h[0] = s[0];
  h[1] = s[1];
  h[2] = s[3];
  h[3] = s[4];
  h[4] = s[6];
  h[5] = s[7];
  bool ok = true;
  for (int i = 0; i < 5; i++)
    if (h[i] != h[i + 1]) ok = false;
  if (ok) return 0;
  ok = true;
  for (int i = 0; i < 5; i++)
    if (h[i] <= h[i + 1]) ok = false;
  if (ok) return 1;
  return 2;
}
void ret(string s) {
  cout << s;
  exit(0);
}
int main() {
  int n, k, mx;
  string s, out[3], name[100000];
  out[0] = "If you want to call a taxi, you should call:";
  out[1] = "If you want to order a pizza, you should call:";
  out[2] =
      "If you want to go to a cafe with a wonderful girl, you should call:";
  int a[3][100000];
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++) a[i][j] = 0;
  for (int i = 0; i < n; i++) {
    cin >> k;
    cin >> name[i];
    for (int j = 0; j < k; j++) {
      cin >> s;
      a[number(s)][i]++;
    }
  }
  mx = 0;
  bool first = true;
  for (int i = 0; i < 3; i++) {
    mx = 0;
    for (int j = 0; j < n; j++) {
      if (a[i][j] > mx) mx = a[i][j];
    }
    first = true;
    cout << out[i];
    for (int j = 0; j < n; j++)
      if (a[i][j] == mx) {
        if (!first) cout << ",";
        cout << " ";
        cout << name[j];
        first = false;
      }
    printf(".\n");
  }
  return 0;
}
