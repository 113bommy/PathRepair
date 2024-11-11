#include <bits/stdc++.h>
#pragma warning(disable : 6031)
using namespace std;
const int maxn = 1e5 + 10;
const long long mode = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979323846264338327950;
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
vector<int> ang;
vector<int> mapp[maxn];
int main() {
  int n, m;
  int flag = 1;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) ang.push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    if (s > t) swap(s, t);
    mapp[s].push_back(t - s);
    mapp[t].push_back(t - s);
  }
  for (int i = 1; i <= n; i++) sort(mapp[i].begin(), mapp[i].end());
  for (int i = 0; i < ang.size(); i++) {
    flag = 1;
    int now = ang[i];
    for (int j = 1; j <= n; j++) {
      if (mapp[j].size() != mapp[(j + now - 1) % n + 1].size()) {
        flag = 0;
        break;
      }
      for (int k = 0; k < mapp[j].size(); k++) {
        if (mapp[(j + now - 1) % n + 1][k] != mapp[j][k]) {
          flag = 0;
          break;
        }
      }
      if (flag == 0) break;
    }
    if (flag == 1) break;
  }
  if (flag == 0)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
