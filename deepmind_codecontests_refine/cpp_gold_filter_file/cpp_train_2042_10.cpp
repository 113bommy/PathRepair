#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
const int INF = 5e8;
int n;
long long int x, y;
int ar[500005], cnt[2100005];
long long int cnt2[2100005];
long long int sum[2100015], sum2[2100015];
const int MAXN = 1000005, MAXM = 200005;
bool table[MAXN];
int pr[MAXM], m;
const int M = 1000093, M2 = M * 2;
void makepr() {
  memset(table, 1, sizeof(table));
  table[0] = table[1] = false;
  for (int i = 2; i * i <= M; ++i)
    if (table[i]) {
      for (int j = i * i; j <= M; j += i) table[j] = false;
    }
  for (int i = 0; i < (M + 1); ++i)
    if (table[i]) pr[m++] = i;
}
int main() {
  cin >> n >> x >> y;
  makepr();
  int wid = x / y;
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &ar[i]);
    ++cnt[ar[i]];
    cnt2[ar[i]] += ar[i];
  }
  for (int i = 0; i < (M2); ++i) {
    sum[i + 1] = sum[i] + (cnt[i]);
    sum2[i + 1] = sum2[i] + cnt2[i];
  }
  long long int res = 1e18;
  for (int i = 0; i < (m); ++i) {
    int g = pr[i];
    long long int cost = 0;
    for (int j = 0; j * g <= M; ++j) {
      int S = j * g + 1, T = (j + 1) * g;
      int S2 = max(S, T - wid);
      cost += (T * (sum[T] - sum[S2]) - (sum2[T] - sum2[S2])) * y;
      cost += (sum[S2] - sum[S]) * x;
    }
    chmin(res, cost);
  }
  cout << res << endl;
  return 0;
}
