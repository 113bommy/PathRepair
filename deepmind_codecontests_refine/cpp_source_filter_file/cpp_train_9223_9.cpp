#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
template <class Int>
Int gcd(Int a, Int b) {
  return (b == 0 ? abs(a) : gcd(b, a % b));
}
const int dx[]{0, 0, 1, -1, 1, -1, 1, -1};
const int dy[]{1, -1, 0, 0, 1, -1, -1, 1};
void run() {}
const int N = 3e5 + 5;
struct nod {
  int l, r, c;
};
unordered_map<int, bool> dp;
int main() {
  cout << setprecision(2) << fixed;
  run();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  map<long long, bool> mp;
  for (long long i = 1; i <= 1e6; i++) mp[i * i * i] = i;
  int n;
  cin >> n;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    long long xy = mp[a * b];
    if (xy * xy * xy == a * b && a % xy == 0 && b % xy == 0)
      cout << "Yes"
           << "\n";
    else
      cout << "No"
           << "\n";
  }
}
