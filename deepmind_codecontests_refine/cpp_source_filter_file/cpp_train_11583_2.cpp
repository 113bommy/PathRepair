#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, k, temp = 0, avail = 0;
    cin >> n >> k;
    int arr[n];
    string s;
    cin >> s;
    if (s.find('1') == -1) {
      s[0] = '1';
      avail++;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        arr[temp] = i;
        temp++;
      }
    }
    if (arr[0] != 0) {
      int d = arr[0];
      avail += d / (k + 1);
    }
    for (int i = 0; i < temp; i++) {
      if (i != temp - 1) {
        int d = arr[i + 1] - arr[i] - 1;
        avail += d / (k + 1);
      } else {
        int d = n - 1 - arr[i];
        avail += d / (k + 1);
      }
    }
    cout << avail << endl;
    t--;
  }
}
