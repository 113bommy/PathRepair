#include <bits/stdc++.h>
using namespace std;
int n, a, b, k, arr[100005];
vector<int> v;
;
int DIV(int a, int b) { return a / b + (a % b > 0); }
bool cmp(int x, int y) { return DIV(x, a) < DIV(y, a); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> a >> b >> k;
  ;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] %= (a + b);
    if (arr[i] == 0) arr[i] = (a + b);
    if (arr[i] > 0 && arr[i] <= a) {
      ans++;
    } else
      v.push_back(arr[i]);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto isi : v) {
    int x = DIV(isi - a, a);
    if (k >= x) {
      k -= x;
      ans++;
    } else
      break;
  }
  cout << ans << endl;
}
