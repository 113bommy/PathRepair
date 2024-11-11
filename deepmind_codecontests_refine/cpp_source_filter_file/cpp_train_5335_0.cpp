#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
long long n, m;
const int mx = 69;
char grid[mx][mx];
long long blocked[mx][mx];
long long vis[mx][mx];
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long power(long long a, long long b) {
  long long res = 1;
  for (int i = 1; i <= b; ++i) res *= a;
  return res;
}
long long sum(long long x) {
  long long ans = 0;
  while (x > 0) {
    ans += (x % 10);
    x /= 10;
  }
  return ans;
}
int main() {
  FAST();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      v.push_back(a);
    }
    if (n == 1) {
      cout << 1 << " " << v[0] << " " << 0 << "\n";
    } else {
      long long sum = 0, temp, flag = 0, i = 0, j = n - 1, sumb = 0, tempb = 0,
                moves = 0, al = 0, bo = 0;
      while (i < j) {
        temp = 0, tempb = 0, flag = 0;
        while (temp <= sum && i <= j) {
          temp += v[i];
          al += v[i];
          i++;
        }
        sumb = temp;
        moves++;
        while (tempb <= sumb && i <= j) {
          tempb += v[j];
          bo += v[j];
          j--;
          flag = 1;
        }
        sum = tempb;
        if (flag) moves++;
      }
      cout << moves << " " << al << " " << bo << '\n';
    }
  }
}
