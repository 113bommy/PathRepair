#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int q, n;
long long k, sz[MAXN];
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string f =
    "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
string st_f = "What are you doing while sending \"";
string md_f = "\"? Are you busy? Will you send \"";
string en_f = "\"?";
char solve(int n, long long k) {
  if (n == 0) {
    if (k >= sz[0])
      return '.';
    else
      return f0[k];
  } else {
    if (n < 53 && k >= sz[n]) return '.';
    if (k < (int)st_f.size())
      return st_f[k];
    else
      k -= (int)st_f.size();
    if (n - 1 >= 53 || k < sz[n - 1])
      return solve(n - 1, k);
    else
      k -= sz[n - 1];
    if (k < (int)md_f.size())
      return md_f[k];
    else
      k -= (int)md_f.size();
    if (k < sz[n - 1])
      return solve(n - 1, k);
    else
      k -= sz[n - 1];
    return en_f[k];
  }
}
int main() {
  sz[0] = f0.size();
  for (int i = 1; i <= 53; i++) sz[i] = 2 * sz[i - 1] + f.size();
  scanf("%d", &q);
  while (q--) {
    scanf("%d %I64d", &n, &k);
    k--;
    printf("%c", solve(n, k));
  }
  printf("\n");
  return 0;
}
