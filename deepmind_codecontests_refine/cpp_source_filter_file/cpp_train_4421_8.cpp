#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, e = 0;
  cin >> n;
  bool valid = false;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      c++;
      valid = true;
    }
    if (valid == true) {
      c++;
      valid = false;
    }
  }
  if (arr[n - 1] == 0 and c > 0) c--;
  cout << c << endl;
}
