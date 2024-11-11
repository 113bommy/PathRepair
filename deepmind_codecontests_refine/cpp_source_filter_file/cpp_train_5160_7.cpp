#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a12, a23, a13;
  cout << "? 1 2" << endl;
  cin >> a12;
  cout << "? 2 3" << endl;
  cin >> a23;
  cout << "? 1 3" << endl;
  cout << a13;
  a[2] = (a23 - a13 + a12) / 2;
  a[1] = a12 - a[2];
  a[3] = a23 - a[2];
  for (int i = 4; i <= n; i++) {
    cout << "? " << i - 1 << " " << i << endl;
    int sum;
    cin >> sum;
    a[i] = sum - a[i - 1];
  }
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << a[i];
  cout << endl;
}
