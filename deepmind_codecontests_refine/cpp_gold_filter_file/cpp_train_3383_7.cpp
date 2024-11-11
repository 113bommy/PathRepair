#include <bits/stdc++.h>
using namespace std;
const int maxn = 1200005;
const int OO = 0x3f3f3f3;
int vis[maxn];
vector<int> p;
int N = 1200000;
void find_prime() {
  p.clear();
  memset(vis, 0, sizeof(vis));
  for (int i = 2; i <= N; i++)
    if (!vis[i])
      for (int j = i * 2; j <= N; j += i) vis[j] = 1;
  for (int i = 2; i <= N; i++)
    if (!vis[i]) p.push_back(i);
}
vector<int> palin;
void find_palin() {
  palin.clear();
  for (int i = 1; i <= 9; i++) {
    palin.push_back(i);
    palin.push_back(i * 11);
  }
  for (int i = 1; i <= 9; i++)
    for (int j = 0; j <= 9; j++) {
      palin.push_back(i * 101 + j * 10);
      palin.push_back(i * 1001 + j * 110);
    }
  for (int i = 1; i <= 9; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 0; k <= 9; k++) {
        palin.push_back(i * 10001 + j * 1010 + k * 100);
        palin.push_back(i * 100001 + j * 10010 + k * 1100);
      }
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 0; k <= 9; k++) {
        palin.push_back(1000001 + i * 100010 + j * 10100 + k * 1000);
      }
  sort(palin.begin(), palin.end());
}
int cnt_prime[maxn], cnt_palin[maxn];
int main() {
  find_prime();
  find_palin();
  memset(cnt_palin, 0, sizeof(cnt_palin));
  memset(cnt_prime, 0, sizeof(cnt_prime));
  for (int i = 2; i <= N; i++) cnt_prime[i] = cnt_prime[i - 1] + 1 - vis[i];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < palin.size(); i++) vis[palin[i]] = 1;
  for (int i = 1; i <= N; i++) cnt_palin[i] = cnt_palin[i - 1] + vis[i];
  int sz = palin.size();
  int ans = -1;
  int x, y;
  scanf("%d%d", &x, &y);
  for (int i = sz - 1; i >= 0; i--)
    if (cnt_prime[palin[i]] * y <= cnt_palin[palin[i]] * x) {
      ans = palin[i];
      break;
    }
  sz = p.size();
  for (int i = sz - 1; i >= 0; i--)
    if (cnt_prime[p[i] - 1] * y <= cnt_palin[p[i] - 1] * x) {
      if (p[i] - 1 > ans) ans = p[i] - 1;
      break;
    }
  if (ans == -1)
    printf("Palindromic tree is better than splay tree\n");
  else
    printf("%d\n", ans);
  return 0;
}
