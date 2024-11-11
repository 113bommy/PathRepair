#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979323846264338;
const int MOD = 1000000007;
int ind = 0;
int cnt = 1;
int arr3[27][200004];
char s[1001000], s2[2000100];
int arr[27][200004];
int arr2[27];
int n, lnth;
int de(int a, int b) {
  int l = 0, r = arr2[a] - 1;
  while (r > l) {
    int m = (l + r) / 2;
    if (arr3[a][m] < b) l = m + 1;
    if (arr3[a][m] >= b) r = m;
    cout << l << " " << r << endl;
  }
  if (arr3[a][l] == b)
    return arr3[a][l];
  else if (arr3[a][l + 1] >= b)
    return arr3[a][l + 1];
  else
    return arr3[a][r];
}
inline int ab(int a, int b) { return (int)(abs(b - a) + 0.000001); }
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d%d%s", &n, &lnth, s);
  for (int i = 0; i < 27; i++) arr2[i] = -1;
  for (int i = 0; i < 26; i++) {
    arr3[i][0] = 500000;
    arr[i][lnth - 1] = 500000;
    arr3[s[0] - 'a'][0] = 0;
    arr[s[lnth - 1] - 'a'][lnth - 1] = lnth - 1;
  }
  arr2[s[lnth - 1] - 'a'] = lnth - 1;
  for (int i = lnth - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      arr[j][i] = arr[j][i + 1];
    }
    arr[s[i] - 'a'][i] = i;
    if (arr2[s[i] - 'a'] == -1) arr2[s[i] - 'a'] = i;
  }
  arr3[s[0] - 'a'][0] = 0;
  for (int i = 1; i < lnth; i++) {
    for (int j = 0; j < 26; j++) {
      arr3[j][i] = arr3[j][i - 1];
    }
    arr3[s[i] - 'a'][i] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", s2);
    int ans = 0;
    int lnth2 = strlen(s2);
    for (int j = 0; j < lnth2; j++) {
      if (arr2[s2[j] - 'a'] == -1) {
        ans += lnth2;
        continue;
      }
      int jj = j;
      if (jj >= lnth) jj = lnth - 1;
      ans += min(ab(j, arr[s2[j] - 'a'][jj]), ab(j, arr3[s2[j] - 'a'][jj]));
    }
    cout << ans << endl;
  }
  return 0;
}
