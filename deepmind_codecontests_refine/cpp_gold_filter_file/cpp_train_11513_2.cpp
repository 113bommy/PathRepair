#include <bits/stdc++.h>
using namespace std;
void File() {}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int lower_bound(int l1, int r1, int x1, vector<int> arr) {
  int l = l1, r = r1, cur = -1, md, x = x1;
  while (l <= r) {
    md = (l + r) / 2;
    if (arr[md] <= x) {
      cur = md;
      l = md + 1;
    } else {
      r = md - 1;
    }
  }
  if (cur != -1 && arr[cur] == x)
    return cur;
  else
    return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int i = 1;
  while (n--) {
    cout << char(i + 96);
    i++;
    if (i > k) {
      i %= k;
    }
  }
  return 0;
}
