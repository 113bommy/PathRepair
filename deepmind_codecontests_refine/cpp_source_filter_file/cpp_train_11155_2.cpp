#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec;
  vec.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (vec[i] + vec[i + 1] == 5 || vec[i] == vec[i + 1]) {
      cout << "Infinite";
      return 0;
    }
  }
  bool overlap = true;
  long long pts = 0;
  int prev = vec[0];
  for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {
    if (i == vec.begin()) continue;
    if (prev == 1) {
      if (*i == 2) {
        pts += 3;
        if (overlap) pts--;
        prev = 2;
      } else
        pts += 4, prev = 3;
      overlap = false;
    } else if (prev == 3) {
      pts += 4;
      overlap = true;
      prev = 1;
    } else
      pts += 3, prev = 1;
  }
  cout << "Finite\n" << pts;
}
