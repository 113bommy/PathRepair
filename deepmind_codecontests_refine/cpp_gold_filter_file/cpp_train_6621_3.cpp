#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
char s[N];
int t[4 * N];
int help[N * 4];
int limit = (int)1e6 * 2;
int ki[N];
vector<int> V[N];
vector<string> Store;
void modify(int x, int b, int e, int l, int r, int v) {
  if (help[x]) return;
  if (b > r || e < l) return;
  if (b >= l && e <= r) {
    help[x] = 1;
    t[x] = v;
    return;
  }
  int m = (b + e) >> 1;
  modify(x + x, b, m, l, r, v);
  modify(x + x + 1, m + 1, e, l, r, v);
  help[x] = help[x + x] & help[x + x + 1];
}
int get(int x, int b, int e, int l, int r) {
  if (t[x] > 0 && (b != e)) {
    t[x + x] = t[x];
    t[x + x + 1] = t[x];
  }
  if (b > r || e < l) return 0;
  if (b >= l && e <= r) {
    return t[x];
  }
  int m = (b + e) >> 1;
  return max(get(x + x, b, m, l, r), get(x + x + 1, m + 1, e, l, r));
}
int main() {
  int n = in(), mx = 0;
  string str = "aa";
  Store.push_back(str);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    str = s;
    Store.push_back(str);
    ki[i] = in();
    for (int j = 1; j <= ki[i]; j++) {
      int di = in();
      V[i].push_back(di);
      mx = max(mx, di + (int)str.size() - 1);
      modify(1, 1, limit, di, di + str.size() - 1, i);
    }
  }
  for (int i = 1; i <= mx; i++) {
    int idx = get(1, 1, limit, i, i);
    if (idx == 0)
      printf("a");
    else {
      int low = 0, high = V[idx].size() - 1, ans = 0;
      while (low <= high) {
        int mid = (low + high) >> 1;
        if (V[idx][mid] <= i) {
          low = mid + 1;
          ans = V[idx][mid];
        } else {
          high = mid - 1;
        }
      }
      printf("%c", Store[idx][i - ans]);
    }
  }
  puts("");
}
