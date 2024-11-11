#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
struct node {
  int s[27];
  int tag, size;
} p[N << 2];
int n, m, temp[30];
char ch[N];
void pushup(int u) {
  for (int i = 1; i <= 26; i++) p[u].s[i] = p[u << 1].s[i] + p[u << 1 | 1].s[i];
  p[u].size = p[u << 1].size + p[u << 1 | 1].size;
}
void build(int u, int ul, int ur) {
  p[u].tag = -1;
  if (ul == ur) {
    int t = ch[ul - 1] - 'a' + 1;
    p[u].s[t] = 1;
    p[u].size = 1;
    return;
  }
  int mid = (ul + ur) >> 1;
  build(u << 1, ul, mid);
  build(u << 1 | 1, mid + 1, ur);
  pushup(u);
}
void pushdown(int u) {
  if (p[u].tag == -1) return;
  if (p[u].tag) {
    int sum = p[u << 1].size;
    for (int i = 1; i <= 26; i++) {
      if (p[u].s[i] && sum) {
        if (sum >= p[u].s[i]) {
          p[u << 1].s[i] = p[u].s[i];
          sum -= p[u].s[i];
          p[u].s[i] = 0;
        } else {
          p[u << 1].s[i] = sum;
          p[u].s[i] -= sum;
          sum = 0;
        }
      } else
        p[u << 1].s[i] = 0;
    }
  } else {
    int sum = p[u << 1].size;
    for (int i = 26; i >= 1; i--) {
      if (p[u].s[i] && sum) {
        if (sum >= p[u].s[i]) {
          p[u << 1].s[i] = p[u].s[i];
          sum -= p[u].s[i];
          p[u].s[i] = 0;
        } else {
          p[u << 1].s[i] = sum;
          p[u].s[i] -= sum;
          sum = 0;
        }
      } else
        p[u << 1].s[i] = 0;
    }
  }
  for (int i = 1; i <= 26; i++) p[u << 1 | 1].s[i] = p[u].s[i];
  p[u << 1].tag = p[u << 1 | 1].tag = p[u].tag;
  p[u].tag = -1;
  pushup(u);
}
void modify(int u, int ul, int ur, int l, int r, int k) {
  if (ul >= l && ur <= r) {
    for (int i = 1; i <= 26; i++) {
      temp[i] += p[u].s[i];
      p[u].s[i] = 0;
    }
    p[u].tag = k;
    return;
  }
  pushdown(u);
  int mid = (ul + ur) >> 1;
  if (mid >= l) modify(u << 1, ul, mid, l, r, k);
  if (mid < r) modify(u << 1 | 1, mid + 1, ur, l, r, k);
}
void merge(int u, int ul, int ur, int l, int r, int k) {
  if (ul >= l && ur <= r) {
    if (k) {
      int sum = p[u].size;
      for (int i = 1; i <= 26 && sum; i++) {
        if (temp[i]) {
          if (sum >= temp[i]) {
            p[u].s[i] = temp[i];
            sum -= temp[i];
            temp[i] = 0;
          } else {
            p[u].s[i] = sum;
            temp[i] -= sum;
            sum = 0;
          }
        }
      }
    } else {
      int sum = p[u].size;
      for (int i = 26; i >= 1 && sum; i--) {
        if (temp[i]) {
          if (sum >= temp[i]) {
            p[u].s[i] = temp[i];
            sum -= temp[i];
            temp[i] = 0;
          } else {
            p[u].s[i] = sum;
            temp[i] -= sum;
            sum = 0;
          }
        }
      }
    }
    return;
  }
  int mid = (ul + ur) >> 1;
  if (mid >= l) merge(u << 1, ul, mid, l, r, k);
  if (mid < r) merge(u << 1 | 1, mid + 1, ur, l, r, k);
  pushup(u);
}
void query(int u, int ul, int ur) {
  if (ul == ur) {
    for (int i = 1; i <= 26; i++) {
      if (p[u].s[i]) {
        cout << char('a' + i - 1);
        return;
      }
    }
  }
  pushdown(u);
  int mid = (ul + ur) >> 1;
  query(u << 1, ul, mid);
  query(u << 1 | 1, mid + 1, ur);
}
void true_main() {
  cin >> n >> m >> ch;
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    modify(1, 1, n, l, r, k);
    merge(1, 1, n, l, r, k);
  }
  query(1, 1, n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    true_main();
  }
  return 0;
}
