#include <bits/stdc++.h>
using namespace std;
long long int cons;
inline long long int check(long long int a) {
  if (a >= cons) a %= cons;
  return a;
}
inline long long int check2(long long int a) {
  a %= cons;
  if (a < 0) a += cons;
  return a;
}
inline long long int fast_check(long long int a) {
  if (a >= cons) a -= cons;
  return a;
}
long long int GCD(long long int a, long long int b) {
  while (a && b) {
    a = a % b;
    if (a != 0) b = b % a;
  }
  return a + b;
}
long long int exp(long long int a, long long int n) {
  long long int ans = 1;
  a = check(a);
  while (n) {
    if (n & 1) ans = check(ans * a);
    a = check(a * a);
    n = (n >> 1);
  }
  return ans;
}
void print_pair(pair<int, int> p) {
  cout << p.first << " " << p.second << endl;
}
long long int nc2(long long int a) { return (a * (a - 1)) / 2; }
long long int nc3(long long int a) {
  long long int b = a * (a - 1) * (a - 2);
  return b / 6;
}
const int N = 3e5 + 1;
long long int previ[N][2];
bool flag[N][2];
long long int zero[N];
long long int one[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cons = 1e9 + 7;
  srand(time(NULL));
  flag[0][0] = flag[0][1] = true;
  long long int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) previ[i][0] = previ[i][1] = 1e9;
  for (int i = 1; i <= n; i++) cin >> zero[i];
  for (int i = 1; i <= n; i++) cin >> one[i];
  long long int arr[2];
  for (int i = 1; i <= n; i++) {
    arr[0] = zero[i];
    arr[1] = one[i];
    for (int j = 0; j < 2; j++) {
      if (!flag[i - 1][j]) continue;
      if (arr[1 - j] >= arr[j]) {
        long long int temp = arr[1 - j] - arr[j] * k;
        if (temp > k) continue;
        flag[i][1 - j] = true;
        previ[i][1 - j] = min(previ[i][1 - j], max((long long int)1, temp));
        if (temp <= 0) {
          flag[i][j] = true;
          previ[i][j] = 1;
        }
      } else {
        long long int temp = arr[j] + previ[i - 1][j] - arr[1 - j] * k;
        if (temp > k) continue;
        flag[i][j] = true;
        previ[i][j] = min(previ[i][j], max((long long int)1, temp));
        if (temp <= 0) {
          flag[i][1 - j] = true;
          previ[i][1 - j] = 1;
        }
      }
    }
  }
  if (flag[n][0] || flag[n][1])
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
