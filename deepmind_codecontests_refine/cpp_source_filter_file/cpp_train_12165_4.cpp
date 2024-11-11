#include<bits/stdc++.h>
using namespace std;

long long c[2e5];

int main() {
  long long n, k; cin >> n >> k;
  while (n--) {
    int a, b; cin >> a >> b;
    c[a] += b;
  }
  int r = 0;
  while (k > 0) {
    k -= c[r++];
  }
  cout << --r << endl;
}
