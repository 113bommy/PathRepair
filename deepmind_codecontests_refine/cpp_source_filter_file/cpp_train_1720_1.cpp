#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long curright = 1;
  long long cur = 1;
  while (true) {
    if (cur + curright >= n) {
      cout << n - cur + 1;
      return 0;
    }
    cur += curright;
    curright++;
  }
  return 0;
}
