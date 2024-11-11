#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k1;
    cin >> k1;
    long long k2;
    cin >> k2;
    int a[k1];
    int b[k2];
    bool flag = false;
    for (int i = 0; i < k1; i++) {
      cin >> a[i];
      if (a[i] == n) {
        flag = true;
      }
    }
    for (int i = 0; i < k2; i++) {
      cin >> b[i];
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "N0" << endl;
    }
  }
}
