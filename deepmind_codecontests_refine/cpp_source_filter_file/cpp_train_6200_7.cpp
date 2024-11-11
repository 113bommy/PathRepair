#include <bits/stdc++.h>
using namespace std;
uint8_t twos_complement(uint8_t val) { return -(unsigned int)val; }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int n, ans = 0;
  cin >> n;
  map<long long int, long long int> m;
  int a[n], i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    int nan = 1;
    for (int j = 0; j < 30; j++) {
      ans += m[nan - a[i]];
      nan <<= 1;
    }
    m[a[i]]++;
  }
  cout << ans << "\n";
}
