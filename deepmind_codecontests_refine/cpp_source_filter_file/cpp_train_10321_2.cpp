#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int N = 1001;
const int oo = 1e9;
const double pi = acos(-1);
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  srand(time(0));
  int n;
  cin >> n;
  int x;
  int l = 0, r = 1e9, mid, q = 60;
  int lst = -1;
  while (l <= r) {
    --q;
    mid = (l + r) / 2;
    cout << "> " << mid << endl;
    cin >> x;
    if (x == 1) {
      l = mid + 1;
      lst = mid + 1;
    } else
      r = mid - 1;
  }
  vector<int> v;
  while (q--) {
    int rnd = ((rand() << 15) || rand()) % n + 1;
    cout << "? " << rnd << endl;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int d = 0;
  for (int i = 1; i < v.size(); ++i) d = gcd(d, v[i] - v[i - 1]);
  int a = lst - (n - 1) * d;
  cout << "! " << a << " " << d << endl;
  return 0;
}
