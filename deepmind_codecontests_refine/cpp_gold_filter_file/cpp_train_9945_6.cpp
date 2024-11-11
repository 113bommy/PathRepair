#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000;
const int MAXM = 200000;
const int INF = 1000000010;
const long long int MOD = 1000000007;
const long long int P = 31;
const long double EPS = 1e-6;
char s[4][4], t[4][4];
int sl = 0, tl = 0;
char S[10], T[10];
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%s", s[0]);
  scanf("%s", s[1]);
  scanf("%s", t[0]);
  scanf("%s", t[1]);
  if (s[0][0] != 'X') S[sl++] = s[0][0];
  if (s[0][1] != 'X') S[sl++] = s[0][1];
  if (s[1][1] != 'X') S[sl++] = s[1][1];
  if (s[1][0] != 'X') S[sl++] = s[1][0];
  for (int i = 0; i < 3; i++) S[sl + i] = S[i];
  sl += 3;
  S[sl] = 0;
  if (t[0][0] != 'X') T[tl++] = t[0][0];
  if (t[0][1] != 'X') T[tl++] = t[0][1];
  if (t[1][1] != 'X') T[tl++] = t[1][1];
  if (t[1][0] != 'X') T[tl++] = t[1][0];
  T[tl] = 0;
  if (!strstr(S, T)) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}
