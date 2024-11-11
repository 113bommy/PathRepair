#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inff = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
template <typename T>
inline T read(T& x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x = f ? -x : x;
}
const int maxn = 200 + 9;
int mp[5][maxn];
int sm[maxn], mx[maxn];
int cur[5];
vector<int> vec;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &mp[i][j]);
      }
    }
    if (m < n) {
      for (int i = 1; i <= n; i++) {
        for (int j = m + 1; j <= n; j++) {
          mp[i][j] = 0;
        }
      }
      m = n;
    }
    int ans = 0;
    vec.clear();
    for (int j = 1; j <= m; j++) {
      sm[j] = 0;
      mx[j] = 0;
      for (int i = 1; i <= n; i++) {
        sm[j] += mp[i][j];
        mx[j] = max(mx[j], mp[i][j]);
      }
      ans = max(ans, sm[j]);
      vec.push_back(mx[j]);
    }
    sort(vec.begin(), vec.end());
    int tp = 0;
    int id = vec.size() - 1;
    for (int i = id; i >= id - n + 1; i--) {
      tp += vec[i];
    }
    ans = max(ans, tp);
    if (n >= 2) {
      for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
          for (int le = 0; le < n; le++) {
            for (int ri = 0; ri < n; ri++) {
              for (int k = 1; k <= n; k++) cur[k] = 0;
              for (int k = 1; k <= n; k++) {
                int nk = (k + le) % n;
                if (nk == 0) nk = n;
                cur[nk] = max(cur[nk], mp[k][i]);
              }
              int tmp = 0;
              for (int k = 1; k <= n; k++) {
                int nk = (k + ri) % n;
                if (nk == 0) nk = n;
                cur[nk] = max(cur[nk], mp[k][j]);
                tmp += cur[nk];
              }
              ans = max(ans, tmp);
            }
          }
        }
      }
    }
    if (n == 4) {
      for (int i = 1; i <= m; i++) {
        vec.clear();
        for (int j = 1; j <= n; j++) {
          if (i == j) continue;
          vec.push_back(mx[j]);
        }
        sort(vec.begin(), vec.end());
        int tmp = 0;
        for (int j = vec.size() - 1; j >= vec.size() - 2; j--) tmp += vec[j];
        vec.clear();
        for (int j = 1; j <= n; j++) vec.push_back(mp[j][i]);
        sort(vec.begin(), vec.end());
        for (int j = vec.size() - 1; j >= vec.size() - 2; j--) tmp += vec[j];
        ans = max(ans, tmp);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
