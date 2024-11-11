#include <bits/stdc++.h>
using namespace std;
void s_y() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  s_y();
  long long n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] != 0) {
    cout << 1 << " " << 1 << "\n";
    cout << (-1) * a[0] << "\n";
    a[0] = 0;
  }
  if (n > 1) {
    cout << 2 << " " << n << "\n";
    for (int i = 1; i < n; i++) {
      cout << (a[i] % n) * (n - 1) << " ";
      a[i] += (a[i] % n) * (n - 1);
    }
    cout << "\n";
    cout << "1 " << n << "\n";
    for (int i = 0; i < n; i++) {
      cout << (-1) * a[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "1 1\n";
    cout << 0 << "\n";
    cout << "1 1\n";
    cout << 0 << "\n";
  }
}
