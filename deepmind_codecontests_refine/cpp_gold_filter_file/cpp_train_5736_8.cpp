#include <bits/stdc++.h>
using namespace std;
const int TAM = 2e5 + 2;
long long n, m, ans = 1, p;
int acum[TAM], arr[TAM];
map<int, int> in;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == m) p = i;
  }
  int sum = 0;
  in[0] = 1;
  for (int i = p - 1; i >= 0; i--) {
    sum += ((arr[i] > m) ? 1 : -1);
    in[sum]++;
    if (sum == 0 or sum == 1) ans++;
  }
  sum = 0;
  for (int i = p + 1; i < n; i++) {
    sum += ((arr[i] > m) ? 1 : -1);
    ans += in[-sum];
    ans += in[-sum + 1];
  }
  cout << ans << "\n";
  return 0;
}
