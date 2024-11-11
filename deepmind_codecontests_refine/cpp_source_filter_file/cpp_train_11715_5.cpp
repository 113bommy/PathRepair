#include <bits/stdc++.h>
using namespace std;
long long an[27];
int md = 1e9 + 7, k, n;
char s[1000001];
vector<int> cy;
bool vis[27];
inline int sum() {
  int x = 0;
  for (int i = 0; i < k + 1; ++i)
    if ((x += an[i]) >= md) x -= md;
  return x;
}
int main() {
  scanf("%d%d%s", &n, &k, s);
  an[0] = 1;
  int i;
  for (i = 0; s[i]; ++i) {
    s[i] -= 'a' - 1;
    an[s[i]] = sum();
  }
  for (--i; i > 0; --i)
    if (!vis[s[i]]) vis[s[i]] = true, cy.push_back(s[i]);
  for (int i = 1; i < k + 1; ++i)
    if (!vis[i]) cy.push_back(i);
  int j = k - 1;
  for (int i = 0; i < n; ++i) {
    if (j == -1) j = k - 1;
    an[cy[j--]] = sum();
  }
  printf("%d", sum());
}
