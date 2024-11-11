#include <bits/stdc++.h>
using namespace std;
int powers[12] = {1,      7,      49,      343,      2401,      16807,
                  117649, 823543, 5764801, 40353607, 282475249, 1977326743};
string conv(int a, int len) {
  string res = "";
  while (a != 0) {
    int y = a % 7;
    a = a / 7;
    res = res + char(y + '0');
  }
  while (res.length() < len) res = res + '0';
  for (int i = 0; i < res.length() / 2; ++i) {
    swap(res[i], res[res.length() - 1 - i]);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int kol1 = 1;
  int kol2 = 1;
  while (n > powers[kol1]) kol1++;
  while (m > powers[kol2]) kol2++;
  if (kol1 + kol2 > 7) {
    cout << 0;
    return 0;
  } else {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        string a1 = conv(i, kol1);
        string a2 = conv(j, kol2);
        set<char> S;
        for (int q = 0; q < a1.length(); ++q) {
          S.insert(a1[q]);
        }
        for (int q = 0; q < a2.length(); ++q) {
          S.insert(a2[q]);
        }
        if ((int)S.size() == (kol1 + kol2)) ans++;
      }
    }
    cout << ans;
  }
  return 0;
}
