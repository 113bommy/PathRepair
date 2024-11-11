#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
const int M = 1100000;
const long long mod = 1e9 + 7;
int n;
string s[N], t[N];
char ans[N];
int num1, num2;
struct node {
  string s;
  int len;
  friend bool operator<(node a, node b) { return a.len < b.len; }
} a[N];
int nn;
int nu[110];
int nu2[110];
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  printf("? 1 %d\n", n);
  fflush(stdout);
  num1 = n * (n + 1) / 2;
  for (int i = 1; i <= num1; i++) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  if (n == 1) {
    printf("! %\n", s[1][0]);
    fflush(stdout);
    return 0;
  }
  num2 = n * (n - 1) / 2;
  printf("? 1 %d\n", n - 1);
  fflush(stdout);
  for (int i = 1; i <= num2; i++) {
    cin >> t[i];
    sort(t[i].begin(), t[i].end());
  }
  sort(s + 1, s + 1 + num1);
  sort(t + 1, t + 1 + num2);
  int head = 1;
  for (int i = 1; i <= num1; i++) {
    if (s[i] == t[head])
      head++;
    else {
      nn++;
      a[nn].s = s[i], a[nn].len = s[i].size();
    }
  }
  sort(a + 1, a + 1 + nn);
  for (int i = 1; i <= nn; i++) {
    memset(nu2, 0, sizeof(nu2));
    for (int j = 0; j < a[i].len; j++) nu2[a[i].s[j] - 'a']++;
    for (int j = 0; j < 26; j++)
      if (nu2[j] > nu[j]) {
        nu[j] = nu2[j];
        ans[nn - i] = j + 'a';
        break;
      }
  }
  printf("! %s\n", ans);
  fflush(stdout);
  return 0;
}
