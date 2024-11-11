#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000 + 9;
long long ans, arr[MAX][2];
string a, b;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> a >> b;
  arr[1][b[0] - '0']++;
  for (int i = 2; i <= b.size(); i++) {
    arr[i][0] = arr[i - 1][0];
    arr[i][1] = arr[i - 1][1];
    arr[i][b[i - 1] - '0']++;
  }
  for (int i = 1; i <= a.size(); i++) {
    int df = !(a[i - 1] - '0');
    ans += arr[b.size() - a.size() + i][df] - arr[i - 1][df];
  }
  cout << ans << '\n';
  return 0;
}
