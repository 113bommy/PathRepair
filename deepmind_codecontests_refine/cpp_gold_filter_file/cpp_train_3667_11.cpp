#include <bits/stdc++.h>
const int N = 1e6 + 5;
using namespace std;
int n, top;
int a[N];
pair<long long, int> st[N];
void nhap() { scanf("%d", &n); }
void xuli() {
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    st[++top] = make_pair(x, 1);
    while (top > 1 && double(st[top].first) / st[top].second <
                          double(st[top - 1].first) / st[top - 1].second) {
      int sl = st[top].second + st[top - 1].second;
      long long val = st[top].first + st[top - 1].first;
      pair<long long, int> T = make_pair(val, sl);
      top--;
      st[top] = T;
    }
  }
  for (int i = 1; i <= top; i++) {
    for (int j = 1; j <= st[i].second; j++) {
      printf("%0.10f\n", double(st[i].first) / st[i].second);
    }
  }
}
int main() {
  nhap();
  xuli();
}
