#include <bits/stdc++.h>
using namespace std;
int T;
char tar[20];
long long num[7];
int f, l;
long long n;
struct Node {
  int a, b, c;
};
vector<Node> t[10];
inline long long calc(int t) {
  long long re = 1;
  while (t--) re *= 10;
  return re;
}
void dfs(int v, int r) {
  if (f || v > l) return;
  if (v == l && !r && !f) {
    for (int i = 1; i <= 6; i++) cout << num[i] << ' ';
    cout << endl;
    f = 1;
    return;
  }
  int ind = (tar[v] - '0' - r + 10) % 10;
  int len = t[ind].size();
  for (int i = 0; i < len; i++) {
    for (int j = 1; j <= t[ind][i].a; j++) num[j] += 4 * calc(v);
    for (int j = t[ind][i].a + 1; j <= t[ind][i].a + t[ind][i].b; j++)
      num[j] += 7 * calc(v);
    dfs(v + 1, (4 * t[ind][i].a + 7 * t[ind][i].b + r) / 10);
    for (int j = 1; j <= t[ind][i].a; j++) num[j] -= 4 * calc(v);
    for (int j = t[ind][i].a + 1; j <= t[ind][i].a + t[ind][i].b; j++)
      num[j] -= 7 * calc(v);
  }
  return;
}
int main() {
  scanf("%d", &T);
  for (int i = 0; i <= 6; i++) {
    for (int j = 0; j <= 6 - i; j++) {
      Node temp;
      temp.a = i, temp.b = j;
      t[(4 * i + 7 * j) % 10].push_back(temp);
    }
  }
  while (T--) {
    f = 0;
    memset(num, 0, sizeof(num));
    scanf("%s", tar);
    l = strlen(tar);
    reverse(tar, tar + l);
    dfs(0, 0);
    if (!f) puts("-1");
  }
  return 0;
}
