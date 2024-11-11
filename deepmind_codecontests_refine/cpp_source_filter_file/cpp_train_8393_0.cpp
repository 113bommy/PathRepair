#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
const long long int N = 1e5;
const long long int L = 1e5;
typedef struct s {
  long long int d1, d2;
} inp;
long long int f[30], p[30];
long long int update() {
  long long int i, cnt = 0;
  for (i = 0; i < 26; i++) {
    if (f[i] == 1 && p[i] == 1)
      p[i] = 1, cnt++;
    else
      p[i] = -1;
  }
  if (cnt == 1)
    return 1;
  else
    return -1;
}
void change() {
  long long int i;
  for (i = 0; i < 30; i++) f[i] = 0;
}
long long int update1() {
  long long int i, cnt = 0;
  for (i = 0; i < 26; i++) {
    if (f[i] == 1 && p[i] == 1) p[i] = -1;
  }
  for (i = 0; i < 25; i++)
    if (p[i] == 1) cnt++;
  if (cnt == 1)
    return 1;
  else
    return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, i, j, k, temp, x, y, z, t, T, a, b, c;
  cin >> n;
  long long int cnt = 0, cnt1 = 0;
  string s;
  for (i = 0; i < 30; i++) {
    f[i] = 0, p[i] = 1;
  }
  getline(cin, s);
  long long int check = 1;
  for (i = 0; i < n; i++) {
    getline(cin, s);
    if (s[0] == '!' || s[0] == '?') {
      if (check == 1 && i != n - 1) cnt1++;
      if (i != n - 1) cnt++;
    }
    if (s[0] == '!' && check == 1) {
      for (j = 2; j < s.length(); j++) f[s[j] - 'a'] = 1;
      if (update() == 1) check = -1;
    }
    if ((s[0] == '.' || s[0] == '?') && check == 1) {
      for (j = 2; j < s.length(); j++) f[s[j] - 'a'] = 1;
      if (update1() == 1) check = -1;
    }
    change();
  }
  cout << cnt - cnt1 << endl;
  return 0;
}
