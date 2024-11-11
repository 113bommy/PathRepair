#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  long long int n, k;
  cin >> n >> k;
  if (k > ((n * (n - 1)) / 2)) {
    cout << "no solution\n";
  } else {
    int a = 0;
    for (int i = 0; i < n; i++) {
      cout << 0 << " " << a << endl;
      a += 1;
    }
  }
}
