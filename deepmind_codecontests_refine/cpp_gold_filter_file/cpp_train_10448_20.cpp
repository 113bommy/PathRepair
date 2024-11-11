#include <bits/stdc++.h>
using namespace std;
void input() {}
long long int prime[1000001] = {};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  vector<long long int> div(1000001, 1);
  for (long long int i = 2; i < 1000001; i++) {
    for (int j = i; j <= 1000000; j += i) {
      div[j]++;
    }
  }
  long long int a, b, c, ans = 0;
  cin >> a >> b >> c;
  for (long long int i = 1; i < a + 1; i++) {
    for (long long int j = 1; j < b + 1; j++) {
      for (long long int k = 1; k < c + 1; k++) {
        ans += div[i * j * k];
        ans %= 1073741824;
      }
    }
  }
  cout << ans << "\n";
}
