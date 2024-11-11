#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p;
long long up[10000], need[1000];
struct q {
  long long tot, price;
} A[1000];
bool cmp(q a, q b) { return a.price < b.price; }
char ch;
void read(int &a) {
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    ;
  for (a = ch - '0', ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
}
long long min2(long long a, long long b) { return (a < b) ? (a) : (b); }
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) cin >> A[i].tot >> A[i].price;
  sort(A + 1, A + 1 + m, cmp);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> up[i], need[i] = up[i] - up[i - 1];
  n++;
  up[n] = 1000000000000000LL;
  need[n] = up[n] - up[n - 1];
  long long ret = 0;
  for (int i = 1, j = 1; i <= m; i++) {
    for (; A[i].tot > 0;) {
      long long res = min2(need[j], A[i].tot);
      A[i].tot -= res;
      ret += ((long long)j) * res * A[i].price;
      need[j] -= res;
      if (need[j] == 0) j++;
    }
  }
  cout << ret << endl;
}
