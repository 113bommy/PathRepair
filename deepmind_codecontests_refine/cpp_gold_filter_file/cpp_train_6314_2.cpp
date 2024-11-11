#include <bits/stdc++.h>
using namespace std;
long long n;
int q;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  while (q--) {
    long long t;
    cin >> t;
    while (~t & 1) {
      t += n - t / 2;
    }
    cout << (t + 1 >> 1) << endl;
  }
}
