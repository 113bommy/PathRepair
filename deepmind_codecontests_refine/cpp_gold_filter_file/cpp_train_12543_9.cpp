#include <bits/stdc++.h>
using namespace std;
int k;
void print(int st) {
  for (int i = 1; i < k; i++) {
    cout << st << ' ' << st + i << '\n';
    cout << st + k << ' ' << st + i << '\n';
    cout << st + k + 1 << ' ' << st + i << '\n';
    for (int j = i + 1; j < i + k / 2; j++) {
      cout << st + i << ' ' << st + (j - 1) % (k - 1) + 1 << '\n';
    }
  }
  cout << st + k << ' ' << st + k + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> k;
  if (k % 2 == 0) {
    cout << "NO";
    return 0;
  }
  if (k == 1) {
    cout << "YES\n2 1\n1 2";
    return 0;
  }
  cout << "YES\n";
  cout << 2 * k + 4 << ' ' << k * (k + 2) << '\n';
  print(1);
  print(k + 3);
  cout << "1 " << k + 3;
}
