#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
void print(int base) {
  if (base == 4) cout << "4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24" << endl;
  if (base == 5)
    cout << "5 * 4 = 20\n3 + 2 = 5\n5 - 1 = 4\n20 + 4 = 24" << endl;
  if (base == 6)
    cout << "4 * 3 = 12\n12 * 2 = 24\n5 + 1 = 6\n6 - 6 = 0\n24 + 0 = 24"
         << endl;
  if (base == 7)
    cout << "5 * 3 = 15\n15 + 7 = 22\n2 - 1 = 1\n22 * 1 = 22\n6 - 4 = 2\n22 + "
            "2 = 24"
         << endl;
}
void solve(int n, int base) {
  print(base);
  if (n == base) return;
  cout << base + 1 << " + " << base + 4 << " = " << 2 * base + 5 << "\n";
  cout << base + 2 << " + " << base + 3 << " = " << 2 * base + 5 << "\n";
  long long sm1 = 2 * base + 5, sm2 = 2 * base + 5, cs = 0;
  for (int i = base + 5; i <= n; i += 2) {
    if (cs) {
      cout << sm1 << " + " << i << " = " << sm1 + i << "\n";
      cout << sm2 << " + " << i + 1 << " = " << sm2 + i + 1 << "\n";
      cs = 0;
      sm1 += i;
      sm2 += i + 1;
    } else {
      cout << sm1 << " + " << i + 1 << " = " << sm1 + i + 1 << "\n";
      cout << sm2 << " + " << i << " = " << sm2 + i << "\n";
      cs = 1;
      sm1 += i + 1;
      sm2 += i;
    }
  }
  cout << sm1 << " - " << sm2 << " = "
       << "0\n";
  cout << "24 + 0 = 24\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  if (n < 4) return puts("NO"), 0;
  cout << "YES" << endl;
  for (int i = 4; i <= 7; ++i) {
    if ((((n - i) / 2) % 2 == 0) && (n - i) % 2 == 0) solve(n, i);
  }
}
