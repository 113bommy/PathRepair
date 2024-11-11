#include <bits/stdc++.h>
using namespace std;
long long ni[] = {1, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
int main() {
  int n;
  cin >> n;
  if (n <= 12) {
    cout << ni[n] << endl;
  } else {
    cout << ni[12] + (n - 12) * 49 << endl;
  }
  return 0;
}
