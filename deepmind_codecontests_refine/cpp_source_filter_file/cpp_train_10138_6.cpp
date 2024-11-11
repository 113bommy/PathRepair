#include <bits/stdc++.h>
using namespace std;
template <typename T>
T trace2(T a, T b) {
  cerr << a << " " << b << '\n';
}
template <typename T>
T trace3(T a, T b, T c) {
  cerr << a << " " << b << " " << c << '\n';
}
template <typename T>
T trace4(T a, T b, T c, T d) {
  cerr << a << " " << b << " " << c << " " << d << '\n';
}
template <typename T>
T trace5(T a, T b, T c, T d, T e) {
  cerr << a << " " << b << " " << c << " " << d << " " << e << '\n';
}
template <typename T>
T trace6(T a, T b, T c, T d, T e, T f) {
  cerr << a << " " << b << " " << c << " " << d << " " << e << " " << f << '\n';
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
template <typename T>
T pow(T a, T b, long long int m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
void swap(long long int *a, long long int *b) {
  long long int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
const long long int N = 1e6;
const long long int x = 2 * 1e5 + 10;
long long int dp[N][2];
bool visit[N][2];
long long int arr[N];
long long int n;
long long int dfs(long long int i, long long int j) {
  if (i < 0 || i > n) {
    return 0;
  }
  if (dp[i][j] == -2) {
    if (visit[i][j] || i == 0) {
      dp[i][j] = -1;
      return dp[i][j];
    }
    visit[i][j] = true;
    long long int temp = arr[i];
    if (j == 0) {
      long long int z = dfs(i - arr[i], 1 - j);
      if (z == -1) {
        temp = 0;
      }
      temp += z;
    } else if (j == 1) {
      long long int z = dfs(i + arr[i], 1 - j);
      if (z == -1) {
        temp = 0;
      }
      temp += z;
    }
    dp[i][j] = temp;
  }
  return dp[i][j];
}
void fuck() {
  cin >> n;
  long long int t = N;
  for (__typeof(t) i = (0) - ((0) > (t)); i != (t) - ((0) > (t));
       i += 1 - 2 * ((0) > (t))) {
    for (__typeof(2) j = (0) - ((0) > (2)); j != (2) - ((0) > (2));
         j += 1 - 2 * ((0) > (2))) {
      dp[i][j] = -2;
      visit[i][j] = false;
    }
  }
  for (__typeof(n) i = (1) - ((1) > (n)); i != (n) - ((1) > (n));
       i += 1 - 2 * ((1) > (n))) {
    cin >> arr[i];
  }
  for (__typeof(n) i = (1) - ((1) > (n)); i != (n) - ((1) > (n));
       i += 1 - 2 * ((1) > (n))) {
    long long int x = dfs(i, 0);
    if (x == -1) {
      cout << x << '\n';
    } else {
      cout << i + x << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  fuck();
  return 0;
}
