#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void print(vector<int> arr) {
  cout << endl;
  for (int i = 0; i < (int)(arr).size(); i++) cout << arr[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) arr[i] = i + 1;
  int cur = 0;
  int swp[2];
  swp[0] = swp[1] = 0;
  int shift = 0;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      cur += -x + n;
      cur %= n;
    } else {
      swp[cur % 2]++;
      swp[cur % 2] %= 2;
      if (swp[0] && swp[1]) {
        shift += (cur % 2 ? 2 : -2);
        swp[0] = swp[1] = 0;
      }
    }
  }
  vector<int> res(n);
  for (int i = 0; i < n; i++)
    res[(i + (i % 2 ? -shift : shift) + n) % n] = arr[i];
  if (swp[0]) {
    for (int i = 0; i < n - 1; i += 2) swap(res[i], res[i + 1]);
  }
  if (swp[1]) {
    for (int i = 0; i < n; i += 2) swap(res[i], res[(i + 1) % n]);
  }
  for (int i = cur; i < cur + n; i++) cout << res[i % n] << " ";
  return 0;
}
