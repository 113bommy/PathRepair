#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &v) {
  for (auto x : v) cout << x << " ";
  cout << "\n";
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t;
  t = 1;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> sumxy(d + 1, 0);
    for (int z = a + b; z <= d; z++) {
      int l = -1, h = -1;
      if ((z - a) >= b && (z - a) <= c) {
        l = a;
      } else if ((z - b) >= a && (z - b) <= b) {
        l = z - b;
      }
      if ((z - b) >= b && (z - b) <= c) {
        h = b;
      } else if ((z - b) >= a && (z - b) <= b) {
        h = z - b;
      }
      if (h != -1 && l != -1) {
        sumxy[z] = h - l + 1;
      }
    }
    long long int ans = (long long int)(b - a + 1) * (long long int)(c - b + 1);
    for (int z = a + b; z < c; z++) {
      ans -= (long long int)sumxy[z];
    }
    long long int fnlans = 0;
    for (int z = c; z <= d; z++) {
      ans -= (long long int)sumxy[z];
      fnlans += ans;
    }
    cout << fnlans << "\n";
  }
}
