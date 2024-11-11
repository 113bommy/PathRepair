#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int INF = 1 << 28;
const long long INFL = 1LL << 62;
int toi(string x) {
  int z;
  istringstream iss(x);
  iss >> z;
  return z;
}
string str[] = {"YES", "NO"};
int modulo(int m, int n) { return m >= 0 ? m % n : (n - abs(m % n)) % n; }
using namespace std;
int arr[101] = {0}, n, m;
int main() {
  cin >> n >> m;
  for (int i = 1, a, b, c; i <= m; i++) {
    cin >> a >> b >> c;
    arr[a] -= c;
    arr[b] += c;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++)
    if (arr[i] > 0) sum += arr[i];
  cout << sum << endl;
  return 0;
}
