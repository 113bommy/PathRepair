#include <bits/stdc++.h>
const int MAXN = 3e5 + 10;
const double eps = 1e-8;
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
typedef struct AC {
  int fair[MAXN], ch[MAXN][26], st[MAXN], tot = 0, sum[MAXN], cnt = 0, rt[21],
                                          key[MAXN];
  queue<int> que;
  AC() {
    for (int i = 0; i <= 20; i++) rt[i] = 0;
  }
  void newnode(int &x) {
    if (tot)
      x = st[tot--];
    else
      x = ++cnt;
    fair[x] = sum[x] = key[x] = 0;
    for (int i = 0; i <= 25; i++) ch[x][i] = 0;
  }
  void insert(char s[]) {
    newnode(rt[0]);
    int len = strlen(s);
    int temp = rt[0];
    for (int i = 0; i < len; i++) {
      int t = s[i] - 'a';
      if (!ch[temp][t]) newnode(ch[temp][t]);
      temp = ch[temp][t];
    }
    key[temp] = 1;
  }
  void merge(int &x, int y) {
    if (x) {
      sum[x] = fair[x] = 0;
    }
    if (!y) return;
    if (!x) {
      x = y;
      return;
    }
    st[++tot] = y;
    key[x] += key[y];
    for (int i = 0; i < 26; i++) merge(ch[x][i], ch[y][i]);
  }
  void Fair(int x) {
    que.push(x);
    while (!que.empty()) {
      int t = que.front();
      que.pop();
      for (int i = 0; i < 26; i++) {
        if (!ch[t][i]) continue;
        if (!fair[t]) {
          fair[ch[t][i]] = x;
          sum[ch[t][i]] = key[ch[t][i]];
          que.push(ch[t][i]);
          continue;
        }
        int temp = fair[t];
        for (; temp && !ch[temp][i]; temp = fair[temp])
          ;
        if (!temp)
          fair[ch[t][i]] = x, sum[ch[t][i]] = key[ch[t][i]];
        else
          fair[ch[t][i]] = ch[temp][i],
          sum[ch[t][i]] = sum[ch[temp][i]] + key[ch[t][i]];
        que.push(ch[t][i]);
      }
    }
  }
  void Insert(char s[]) {
    insert(s);
    for (int i = 1; i <= 20; i++) {
      if (rt[i]) {
        merge(rt[i], rt[i - 1]);
        rt[i - 1] = 0;
      } else {
        merge(rt[i], rt[i - 1]);
        rt[i - 1] = 0;
        Fair(rt[i]);
        break;
      }
    }
  }
  int querty(char s[]) {
    int len = strlen(s);
    int ans = 0;
    for (int i = 1; i <= 20; i++) {
      if (!rt[i]) continue;
      int temp = rt[i];
      for (int j = 0; j < len; j++) {
        int t = s[j] - 'a';
        if (!ch[temp][t]) {
          int p = temp;
          for (; p && !ch[p][t]; p = fair[p])
            ;
          if (!p)
            temp = rt[i];
          else
            temp = ch[p][t];
        } else
          temp = ch[temp][t];
        ans += sum[temp];
      }
    }
    return ans;
  }
} AC;
AC *add, *delet;
char str[MAXN];
int main() {
  int m = read();
  add = new AC();
  delet = new AC();
  while (m--) {
    int op = read();
    scanf("%s", str);
    if (op == 1)
      add->Insert(str);
    else if (op == 2)
      delet->Insert(str);
    else
      printf("%d\n", add->querty(str) - delet->querty(str));
    fflush(stdout);
  }
  return 0;
}
