#include <bits/stdc++.h>
int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dr1[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dr2[] = {0, 0, 1, -1};
int dc2[] = {1, -1, 0, 0};
using namespace std;
unsigned long long int has = 31;
unsigned long long int pr[200005], a[26][200005];
long long int b[30], fr[30];
void pre() {
  long long int i, j;
  pr[0] = 1;
  for (i = 1; i < 200005; i++) pr[i] = pr[i - 1] * has;
}
char t[200005], t1[200005];
int main() {
  long long int n, m, i, j;
  char ch;
  pre();
  while (cin >> n >> m) {
    for (i = 1; i <= n; i++) {
      cin >> ch;
      t[i] = ch;
      long long int p = ch - 'a';
      a[p][i] += pr[i];
    }
    unsigned long long int s = 0;
    for (i = 1; i <= m; i++) {
      cin >> ch;
      t1[i] = ch;
      long long int p = ch - 'a';
      if (b[p] == 0) b[p] = i;
      s += (p * pr[i]);
    }
    for (i = 0; i < 26; i++) {
      for (j = 1; j <= n; j++) {
        a[i][j] += a[i][j - 1];
      }
    }
    vector<long long int> ans;
    for (i = 1; i + m - 1 <= n; i++) {
      for (j = 0; j < 26; j++) fr[j] = j;
      for (j = 0; j < 26; j++) {
        if (b[j] == 0) continue;
        if (t[i + b[j] - 1] != t1[b[j]]) {
          long long int x = t[i + b[j] - 1] - 'a';
          long long int y = t1[b[j]] - 'a';
          if (fr[x] != x || fr[y] != y) continue;
          fr[x] = y;
          fr[y] = x;
        }
      }
      unsigned long long int s1 = 0;
      for (j = 0; j < 26; j++) {
        long long int p = fr[j];
        long long int x = a[p][i + m - 1] - a[p][i - 1];
        s1 += (j * x);
      }
      unsigned long long int s2 = s * pr[i - 1];
      if (s2 == s1) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    if (i > 0) cout << endl;
  }
  return 0;
}
