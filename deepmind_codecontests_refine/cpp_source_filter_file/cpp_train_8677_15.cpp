#include <bits/stdc++.h>
using namespace std;
int pr[1000001];
int main() {
  for (int i = 2; i < 1000000; i++)
    for (int j = 2; j * i <= 999999; j++) {
      pr[i * j] = 1;
    }
  int n;
  cin >> n;
  long long int x;
  for (int i = 0; i < n; i++) {
    int c = 0;
    cin >> x;
    if (x == 1) {
      cout << "NO" << endl;
      continue;
    }
    long long int sq = (int)(sqrt(x));
    long long int y = sq * sq;
    if (pr[sq] == 0 && y == x)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
