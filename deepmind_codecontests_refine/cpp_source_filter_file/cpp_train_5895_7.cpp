#include <bits/stdc++.h>
using namespace std;
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T min(T a, T b, T c, T d) {
  return min(a, min(b, min(c, d)));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T max(T a, T b, T c, T d) {
  return max(a, max(b, max(c, d)));
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.first > b.first || (a.first == b.first && a.second >= b.second));
}
long long GCD(long long a, long long b) { return (a % b) ? GCD(b, a % b) : b; }
const string namePro = "tmp";
int a[100007], t[100007], l[100007], r[100007];
int main() {
  int n, q, m;
  scanf("%d%d%d", &n, &q, &m);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = (1); i <= (q); ++i) scanf("%d%d%d", &t[i], &l[i], &r[i]);
  for (int i = (1); i <= (m); ++i) {
    int x;
    scanf("%d", &x);
    for (int j = (q); j >= (1); --j) {
      if (x >= l[j] && x <= r[j]) {
        if (t[j] == 1) {
          if (x == l[j])
            x = r[j];
          else
            --x;
        } else
          x = r[j] + l[j] - x;
      }
    }
    cout << a[x] << " ";
  }
  return 0;
}
