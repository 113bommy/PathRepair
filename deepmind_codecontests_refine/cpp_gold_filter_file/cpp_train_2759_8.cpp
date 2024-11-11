#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > V;
int n, k;
struct ANS {
  char C[10000010];
  int l;
  ANS() { l = 0; }
  void append(char *ch, int len, int rev = 0) {
    if (!rev)
      for (int i = 0; i < len; i++) C[++l] = ch[i];
    else
      for (int i = len - 1; i >= 0; i--) C[++l] = ch[i];
  }
  void Solve(char *ch, int len) {
    for (int i = 0; i <= len; i++)
      if (i == len || ch[i] != ch[len - 1 - i]) {
        append(ch, len, i == len ? 0 : ch[i] > ch[len - 1 - i]);
        return;
      }
  }
  void print() {
    for (int i = 1; i <= l; i++) putchar(C[i]);
    putchar('\n');
  }
  bool operator<(const ANS &X) {
    int tmp = strncmp(C + 1, X.C + 1, n);
    return tmp < 0;
  }
} Ans, Tmp, Tmp2;
char ch[10000010];
int Z[10000010];
void zalg() {
  Z[1] = 2 * n + 1;
  for (int i = 2, j = 1, r = 1; i <= 2 * n + 1; i++) {
    Z[i] = max(min(r - i + 1, Z[i - j + 1]), 0);
    while (ch[Z[i] + 1] == ch[Z[i] + i]) Z[i]++;
    if (i + Z[i] - 1 > r) {
      r = i + Z[i] - 1;
      j = i;
    }
  }
}
int main() {
  scanf("%s%d", ch + 1, &k);
  n = strlen(ch + 1);
  reverse(ch + 1, ch + n + 1);
  for (int i = 1; i <= n; i++) ch[n * 2 + 2 - i] = ch[i];
  ch[n + 1] = '#';
  for (int i = 1, j = 1, k = 2; k <= n + 1; k++)
    if (ch[k] >= ch[j])
      j = ch[k] == ch[j] ? j + 1 : i;
    else {
      V.push_back(pair<int, int>(i, k - j));
      while (i <= j) i += k - j;
      k = (j = i);
    }
  zalg();
  int l = 1, t = V.size() - 1;
  V.push_back(pair<int, int>(n + 1, 0));
  while (k > 2 && t) {
    if (V[t].second == 1)
      while (V[t].second == 1 && t)
        Ans.append(ch + V[t].first, V[t + 1].first - V[t].first), t--;
    else
      Ans.append(ch + V[t].first, V[t + 1].first - V[t].first), t--;
    k--;
  }
  if (k == 1 || t <= 0)
    Ans.Solve(ch + 1, V[t + 1].first - 1);
  else {
    Tmp2 = (Tmp = Ans);
    Ans.append(ch + V[t].first, V[t + 1].first - V[t].first);
    Tmp.append(ch + V[t - 1].first, V[t + 1].first - V[t - 1].first);
    Ans.Solve(ch + 1, V[t].first - 1);
    Tmp.Solve(ch + 1, V[t - 1].first - 1);
    if (Tmp < Ans) Ans = Tmp;
    int ans = V[t + 1].first;
    for (int i = V[t + 1].first - 1; i >= 1; i--) {
      int a = n * 2 + 2 - (ans - 1), p = Z[a];
      if (p < ans - i) {
        if (ch[p + 1] > ch[a + p]) ans = i;
      } else {
        p = Z[ans - i + 1];
        if (ch[p + 1] < ch[p + (ans - i) + 1]) ans = i;
      }
    }
    Tmp2.append(ch + ans, V[t + 1].first - ans, 1);
    Tmp2.append(ch + 1, ans - 1);
    if (Tmp2 < Ans) Ans = Tmp2;
  }
  Ans.print();
  return 0;
}
