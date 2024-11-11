#include <bits/stdc++.h>
using namespace std;
int yo1[1000000], yo2[1000000];
int main() {
  int n;
  cin >> n;
  string arr;
  cin >> arr;
  yo1[0] = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1])
      yo1[i] = yo1[i - 1];
    else
      yo1[i] = i;
  }
  yo2[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] == arr[i + 1])
      yo2[i] = yo2[i + 1];
    else
      yo2[i] = i;
  }
  long long coun = 0, hi = n * (n - 1) / 2;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 'A') {
      if (arr[i - 1] == 'B' && i > 0) {
        coun += i - yo1[i - 1];
      }
      if (arr[i + 1] == 'B' && i + 1 < arr.size()) {
        coun += yo2[i + 1] - i;
        coun--;
      }
    } else {
      if (arr[i - 1] == 'A' && i > 0) {
        coun += i - yo1[i - 1];
      }
      if (arr[i + 1] == 'A' && i + 1 < arr.size()) {
        coun += yo2[i + 1] - i;
        coun--;
      }
    }
  }
  hi -= coun;
  cout << hi;
  return 0;
}
