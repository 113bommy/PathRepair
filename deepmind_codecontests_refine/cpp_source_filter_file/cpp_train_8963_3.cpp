#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int times = 1;
  for (int i = 0; i < times; i++) {
    solve();
    cout << '\n';
  }
  return 0;
}
int a, b, c, d, e, f, g, h;
int arr[500000 + 50], arr1[500000 + 50], arr2[500000 + 50], from[500000 + 50];
void solve() {
  int Q;
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    char type;
    cin >> type;
    arr1[i] = arr1[i - 1];
    arr2[i] = arr2[i - 1];
    if (type == 'L') {
      arr1[i]++;
      cin >> a;
      arr[a] = i;
      from[a] = 1;
    } else if (type == 'R') {
      arr2[i]++;
      cin >> a;
      arr[a] = i;
      from[a] = 2;
    } else {
      cin >> a;
      if (from[a] == 1) {
        cout << min(arr1[i] - arr1[arr[a]], arr2[i] + arr1[arr[a]]) << '\n';
      } else {
        cout << min(arr1[i] + arr2[arr[a]], arr2[i] - arr2[arr[a]]) << '\n';
      }
    }
  }
}
