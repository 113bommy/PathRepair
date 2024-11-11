#include <bits/stdc++.h>
using namespace std;
int main() {
  int s[1000] = {0}, n, k = 0;
  cin >> n;
  for (int i(0); i < (n); i++) {
    int N;
    cin >> N;
    s[N + 100] = 1;
  }
  for (int i(0); i < (201); i++) {
    k += s[i];
    if (k == 2) {
      cout << i - 100;
      return 0;
    }
  }
  cout << "NO";
}
