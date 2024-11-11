#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int idx = n;
  for (int i = 0; i < n - 1; i++) {
    if (str[i] >= str[i + 1]) {
      idx = i;
      break;
    }
  }
  for (int k = 0; k < idx; k++) cout << str[k];
  for (int k = idx + 1; k < n; k++) cout << str[k];
}
