#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long num, sum;
    cin >> num >> sum;
    long long check = num / 2 + 1;
    cout << (long long)(floor(sum / check)) << endl;
  }
  return 0;
}
