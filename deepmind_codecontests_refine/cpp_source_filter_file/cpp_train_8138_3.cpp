#include <bits/stdc++.h>
using namespace std;
const int N = 500005, mod = 1000000007;
long long int a, b, c, d, e, f, g, h[N], arr[N], ar[N], tree[N];
string s;
vector<long long int> v;
void upd(long long int n, long long int l, long long int r, long long int x,
         long long int y, long long int updval) {
  if (y < x) return;
  if (x <= l and r <= y) {
    tree[n] += updval * (r - l + 1);
    while (n / 2) {
      n /= 2;
      tree[n] += updval * (r - l + 1);
    }
    return;
  }
  if (x > r or y < l) {
    return;
  }
  if (tree[n] != tree[2 * n] + tree[2 * n + 1]) {
    long long int awdasda =
        (tree[n] - (tree[2 * n] + tree[2 * n + 1])) / (r - l + 1);
    tree[2 * n] += awdasda * ((l + r) / 2 - l + 1);
    tree[2 * n + 1] += awdasda * (r - ((l + r) / 2 + 1) + 1);
  }
  upd(n * 2, l, (l + r) / 2, x, y, updval);
  upd(n * 2 + 1, (l + r) / 2 + 1, r, x, y, updval);
}
void cikar(long long int n, long long int l, long long int r) {
  if (l == r) {
    ar[l] = tree[n];
    return;
  }
  if (e == 4) {
    cout << tree[n] << endl;
  }
  if (tree[n] != tree[2 * n] + tree[2 * n + 1]) {
    long long int awdasda =
        (tree[n] - (tree[2 * n] + tree[2 * n + 1])) / (r - l + 1);
    tree[2 * n] += awdasda * ((l + r) / 2 - l + 1);
    tree[2 * n + 1] += awdasda * (r - ((l + r) / 2 + 1) + 1);
  }
  cikar(n * 2, l, (l + r) / 2);
  cikar(n * 2 + 1, (l + r) / 2 + 1, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b;
  for (long long int i = 1; i <= b; i++) {
    cin >> arr[i];
  }
  for (long long int i = 1; i < b; i++) {
    if (arr[i] == arr[i + 1]) continue;
    upd(1, 1, a, 1, a, abs(arr[i] - arr[i + 1]));
    upd(1, 1, a, arr[i], arr[i],
        (arr[i + 1] > arr[i] ? arr[i + 1] - 1 : arr[i + 1]) -
            abs(arr[i] - arr[i + 1]));
    upd(1, 1, a, arr[i + 1], arr[i + 1],
        (arr[i] > arr[i + 1] ? arr[i] - 1 : arr[i]) - abs(arr[i] - arr[i + 1]));
    upd(1, 1, a, min(arr[i], arr[i + 1]) + 1, max(arr[i], arr[i + 1]) - 1, -1);
  }
  cikar(1, 1, a);
  for (long long int i = 1; i <= a; i++) {
    cout << ar[i] << ' ';
  }
}
