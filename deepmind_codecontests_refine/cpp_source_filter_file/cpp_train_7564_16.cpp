#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int i;
  char *arr = new char[s.size() + 1];
  strcpy(arr, s.c_str());
  for (i = 1; i <= k; i++) {
    if (k % i == 0) {
      reverse(arr, arr + i);
    }
  }
  for (i = 0; i < s.size() + 1; i++) {
    cout << arr[i];
  }
  return 0;
}
