#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int arr[10];
int main() {
  ios::sync_with_stdio(false);
  int k;
  string n;
  long long sn = 0;
  cin >> k >> n;
  for (int i = 0; i < n.length(); i++) {
    sn += n[i] - '0';
    if (sn >= k) {
      cout << 0 << endl;
      return 0;
    }
    arr[n[i] - '0']++;
  }
  int r = 0;
  for (int i = 0; i < 10 && sn < k; i++) {
    while (arr[i] != 0) {
      sn += 9 - arr[i];
      r++;
      if (sn >= k) {
        cout << r << endl;
        return 0;
      }
      arr[i]--;
    }
  }
  cout << r << endl;
  return 0;
}
