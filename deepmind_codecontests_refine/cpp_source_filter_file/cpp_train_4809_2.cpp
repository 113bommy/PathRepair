#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n], last = 0;
    vector<int> small;
    bool found[100000] = {false}, ok = true;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
      int x = arr[i];
      x--;
      while (x > last) {
        small.push_back(x);
        x--;
      }
      last = arr[i];
    }
    sort(small.begin(), small.end(), greater<int>());
    for (int i = 0; i < n; i++) {
      int x = arr[i];
      if (found[x] && !small.empty()) {
        int a = small.size() - 1;
        int b = small[a];
        if (arr[i] > b) {
          arr[i] = small[a];
          small.pop_back();
        } else {
          ok = false;
          break;
        }
      } else if (found[x]) {
        ok = false;
        break;
      }
      found[x] = true;
    }
    if (ok)
      for (int i = 0; i < n; i++) cout << arr[i] << " ";
    else
      cout << -1;
    cout << endl;
  }
}
