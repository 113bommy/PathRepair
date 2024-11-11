#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, s, counter = 5001, arr[5001];
  cin >> s;
  for (i = 0; i < s; i++) {
    cin >> arr[i];
  }
  while (counter--) {
    for (i = 0; i < s; i++) {
      if (arr[i] != i) break;
      if (i == s - 1 && arr[i] == i) {
        cout << "Yes";
        return 0;
      }
    }
    for (i = 0; i < s; i++) {
      if (i % 2 == 0) {
        if (arr[i] == s - 1)
          arr[i] = 0;
        else
          arr[i]++;
      } else {
        if (arr[i] == 0)
          arr[i] = s - 1;
        else
          arr[i]--;
      }
    }
    for (i = 0; i < s; i++) {
      if (arr[i] != i) break;
      if (i == s - 1 && arr[i] == i) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}
