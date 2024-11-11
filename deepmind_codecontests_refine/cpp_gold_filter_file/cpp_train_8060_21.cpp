#include <bits/stdc++.h>
using namespace std;
long long a, b, c[110];
int main() {
  cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + a + 1);
  cout << c[a - b + 1] << endl;
  return 0;
}
