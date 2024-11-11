#include <bits/stdc++.h>
using namespace std;
long long v[200004];
int main() {
  long long n, x;
  cin >> n >> x;
  long long ans = 0;
  while (n--) {
    int a;
    cin >> a;
    ans = ans + v[x ^ a];
    v[a]++;
  }
  cout << ans << endl;
}
