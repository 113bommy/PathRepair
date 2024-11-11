#include <bits/stdc++.h>
using namespace std;
void go() {
  int cnt = 1, maxx = 0, n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1])
      cnt++;
    else
      cnt = 1;
    maxx = max(maxx, cnt);
  }
  cout << maxx << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  go();
  return 0;
}
