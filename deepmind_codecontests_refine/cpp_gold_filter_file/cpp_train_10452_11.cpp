#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wmissing-declarations"
inline int safe_mul(int x, int y) __attribute__((warn_unused_result));
struct Item {
  int a;
  int b;
  int num;
};
int const maxn = 100005;
Item arr[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  int n, p, k;
  cin >> n >> p >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].a >> arr[i].b;
    arr[i].num = i + 1;
  }
  sort(arr, arr + n, [](const Item& x, const Item& y) {
    return make_pair(x.b, -x.a) < make_pair(y.b, -y.a);
  });
  sort(arr + p - k, arr + n, [](const Item& x, const Item& y) {
    return make_pair(x.a, x.b) > make_pair(y.a, y.b);
  });
  vector<Item> ans;
  pair<int, int> maxN(1000000001, 0);
  for (int i = p - k; i < p; ++i) {
    ans.emplace_back(arr[i]);
    if (make_pair(arr[i].b, -arr[i].a) < maxN) maxN = {arr[i].b, -arr[i].a};
  }
  vector<Item> na;
  for (int i = 0; i < n; ++i)
    if ((i < p - k || i >= p) && (make_pair(arr[i].b, -arr[i].a) <= maxN))
      na.push_back(arr[i]);
  sort(na.begin(), na.end(), [](const Item& x, const Item& y) {
    return make_pair(x.b, -x.a) > make_pair(y.b, -y.a);
  });
  for (int i = 0; i < p - k; ++i) ans.emplace_back(na[i]);
  for (int i = 0; i < p; ++i) cout << ans[i].num << " \n"[i == p - 1];
}
