#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long n;
long long need[N];
int main() {
  cin >> n;
  if (n == 2) {
    cout << 1 << endl;
    exit(0);
  } else if (n == 3) {
    cout << 2 << endl;
    exit(0);
  }
  need[1] = 1;
  need[2] = 2;
  for (int i = 3;; ++i) {
    int killed = (i - 1);
    need[i] = 1 + need[i - 1] + need[killed - 1];
    if (n < need[i]) {
      cout << i - 1 << endl;
      exit(0);
    }
  }
  return 0;
}
