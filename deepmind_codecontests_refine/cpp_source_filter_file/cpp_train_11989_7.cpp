#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long res = 0;
  for (int i = 0; i < 26; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j][0] == (i + 97)) {
        count++;
      }
    }
    if (count > 2 && count % 2 == 0) {
      count = count / 2;
      res += (count) * (count - 1);
    }
    if (count > 2 && count % 2 == 1) {
      count = count / 2 + 1;
      res += ((count) * (count - 1)) / 2;
      count = count - 1;
      res += ((count) * (count - 1)) / 2;
    }
  }
  cout << res << "\n";
}
