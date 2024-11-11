#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, c;
  cin >> n >> t >> c;
  long long ara[n + 5];
  for (int i = 1; i <= n; i++) cin >> ara[i];
  long long counter = 0;
  long long i = 1;
  for (int j = i; j <= n; j++) {
    if (j == n) {
      if (ara[j] > t) {
        if ((j - i) >= c) counter += j - i - c + 1;
      } else if (j - i + 1 >= c)
        counter += j - i - c + 2;
    } else if (ara[j] > t) {
      if ((j - i) >= c) counter += j - i - c + 1;
      i = j + 1;
    }
  }
  cout << counter << endl;
  return 0;
}
