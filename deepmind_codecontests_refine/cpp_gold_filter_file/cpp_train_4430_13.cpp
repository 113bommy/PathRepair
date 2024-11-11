#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long a[] = {4, 9, 25, 49}, i, count;
  for (i = 0; i < 4; i++) {
    cout << a[i] << "\n";
    fflush(stdout);
    cin >> s;
    if (s == "yes") {
      cout << "composite";
      return 0;
    }
  }
  long long b[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  count = 0;
  for (i = 0; i < 15; i++) {
    cout << b[i] << "\n";
    fflush(stdout);
    cin >> s;
    if (s == "yes") count++;
  }
  if (count >= 2) {
    cout << "composite";
  } else
    cout << "prime";
  return 0;
}
