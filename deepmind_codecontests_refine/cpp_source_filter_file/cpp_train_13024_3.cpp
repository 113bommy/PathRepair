#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n = 0, s = 0;
  cin >> n >> s;
  if (s > n) {
    if (s % n != 0) {
      cout << (s % n + 1);
    } else {
      cout << (s / n);
    }
  } else {
    cout << 1;
  }
}
