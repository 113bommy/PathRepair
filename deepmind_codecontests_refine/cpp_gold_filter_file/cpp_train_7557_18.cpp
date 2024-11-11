#include <bits/stdc++.h>
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
using namespace std;
const int maxn = 1e5 + 5;
char P[maxn], Q[maxn];
int main() {
  char ch[27];
  int F[27];
  bool vis = false;
  memset(F, 0, sizeof(F));
  scanf("%s", ch);
  for (long long i = 0; i < strlen(ch); i++) F[ch[i] - 'a'] = 1;
  scanf("%s", P);
  int n;
  scanf("%d", &n);
  int k1 = strlen(P);
  for (long long i = 0; i < k1; i++)
    if (P[i] == '*') {
      vis = true;
      break;
    }
  for (long long o = 0; o < n; o++) {
    scanf("%s", Q);
    int k2 = strlen(Q);
    if (vis) {
      if (k1 > k2 + 1) {
        cout << "NO" << endl;
        continue;
      }
    } else {
      if (k1 != k2) {
        cout << "NO" << endl;
        continue;
      }
    }
    int v = 0, m = 0;
    bool fond = true;
    for (long long i = 0; i < k1; i++) {
      if (v) {
        if (P[i] == Q[i + m])
          continue;
        else if (P[i] == '?' && F[Q[i + m] - 'a'] == 1)
          continue;
        else {
          fond = false;
          break;
        }
        continue;
      }
      if (P[i] == Q[i])
        continue;
      else if (P[i] == '?' && F[Q[i] - 'a'] == 1)
        continue;
      else if (P[i] == '*') {
        if (k1 == k2 + 1) {
          v = 1;
          m = -1;
        } else if (k1 == k2) {
          if (F[Q[i] - 'a'] == 1) {
            fond = false;
            break;
          }
        } else if (k1 < k2) {
          v = 1;
          m = k2 - k1;
          bool fond1 = true;
          for (long long j = 0; j < m + 1; j++) {
            if (F[Q[i + j] - 'a'] == 1) {
              fond1 = false;
              break;
            }
          }
          if (!fond1) {
            fond = false;
            break;
          }
        }
      } else {
        fond = false;
        break;
      }
    }
    if (fond)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
