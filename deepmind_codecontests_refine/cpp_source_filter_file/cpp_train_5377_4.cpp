#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, count = 0;
  cin >> n;
  if (n <= 2) {
    cout << "1" << endl;
  } else {
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        if (n / i == i)
          count++;
        else
          count += 2;
      }
    }
  }
  cout << count - 1 << endl;
  return 0;
}
