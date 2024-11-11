#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
pair<int, int> a[MAXN];
int n;
struct T {
  int a, b, idx;
  T(int a = 0, int b = 0, int idx = 0) : a(a), b(b), idx(idx) {}
  bool operator<(const T &other) const { return a > other.a; }
} arr[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i].a;
  for (int i = 1; i <= n; i++) cin >> arr[i].b;
  for (int i = 1; i <= n; i++) arr[i].idx = i;
  sort(arr + 1, arr + 1 + n);
  cout << n / 2 + 1 << endl;
  cout << arr[1].idx << " ";
  for (int i = 2; i <= n; i += 2) {
    if (arr[i].b > arr[i + 1].b)
      cout << arr[i].idx << " ";
    else
      cout << arr[i + 1].idx << " ";
  }
  return 0;
}
