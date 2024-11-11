#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < int(n); i++) {
    cin >> arr[i];
  }
  int mx = -1;
  for (int l = 0; l < int(n); l++) {
    bool ok = 1;
    set<int> ss;
    for (int i = 0; i < int(l); i++) {
      if (ss.find(arr[i]) != ss.end()) {
        break;
      } else
        ss.insert(arr[i]);
    }
    for (int i = n - 1; i >= l; i--) {
      if (ss.find(arr[i]) != ss.end()) {
        break;
      } else
        ss.insert(arr[i]);
    }
    int c = ss.size();
    mx = max(mx, c);
  }
  cout << n - mx << "\n";
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  ;
  return 0;
}
