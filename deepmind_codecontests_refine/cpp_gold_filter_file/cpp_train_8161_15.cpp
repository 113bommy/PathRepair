#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T MAX(T a, T b) {
  if (a > b) return a;
  return b;
}
template <class T>
inline T MIN(T a, T b) {
  if (a < b) return a;
  return b;
}
template <class T>
inline T ABS(T x) {
  if (x < 0) return -x;
  return x;
}
inline void OPEN(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const static int INF = 1000000000;
int n, k;
int arr[105][105];
int main() {
  scanf("%d%d", &n, &k);
  for (int(i) = (0); (i) < (n); ++(i))
    for (int(j) = (0); (j) < (n); ++(j)) arr[i][j] = 1;
  for (int(i) = (0); (i) < (n); ++(i)) arr[i][i] = k - (n - 1);
  for (int(i) = (0); (i) < (n); ++(i)) {
    for (int(j) = (0); (j) < (n); ++(j)) {
      if (j != 0) printf(" ");
      printf("%d", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
