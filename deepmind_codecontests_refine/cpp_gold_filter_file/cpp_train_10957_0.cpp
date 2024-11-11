#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int k = 0;
    vector<int> p;
    for (int i = n - 1; i >= 0; --i, k++) {
      int startid;
      bool inc;
      bool rev;
      if (k % 2 == 0) {
        startid = k / 2;
        inc = true;
      } else {
        startid = n - 1 - k / 2;
        inc = false;
      }
      rev = k % 2;
      int ca = a[startid] - '0';
      if (rev) ca = 1 - ca;
      if (ca != b[i] - '0') {
        p.push_back(i + 1);
      } else {
        p.push_back(1);
        p.push_back(i + 1);
      }
    }
    cout << p.size() << "\n";
    for (int i : p) cout << i << " ";
    cout << "\n";
  }
}
