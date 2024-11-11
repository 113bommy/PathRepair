#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename... Args>
void read(Args&... args) {
  ((cin >> args), ...);
}
template <typename... Args>
void print(Args... args) {
  ((cout << args << " "), ...);
}
template <typename... Args>
void println(Args... args) {
  ((cout << args << "\n"), ...);
}
template <typename Args>
void kill(Args args) {
  cout << args << "\n";
  exit(0);
}
const double PI = acos(-1);
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1010101;
int rgt[N], lst[N], arr[N];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) lst[i] = n + 1;
  for (int i = n; i >= 1; i--) {
    rgt[i] = lst[arr[i]];
    lst[arr[i]] = i;
  }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    long long sum = 1ll * (rgt[i] - i) * i;
    sum *= 2;
    sum--;
    ans += sum;
  }
  cout << ans / (double)(n * 1ll * n) << "\n";
  return 0;
}
