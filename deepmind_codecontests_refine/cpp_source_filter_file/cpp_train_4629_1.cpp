#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
void solve() {
  long long int n;
  cin >> n;
  if (n < 4) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  long long int rem = n % 4;
  if (rem == 0) {
    cout << "1 * 2 = 3\n";
    cout << "3 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
    long long int now = n / 4;
    for (long long int i = 2; i <= now; i++) {
      long long int nanu = (i - 1) * 4 + 1, motu = i * 4;
      cout << nanu << " + " << motu << " = " << nanu + motu << "\n";
      cout << nanu + 1 << " + " << motu - 1 << " = " << nanu + motu << "\n";
      cout << nanu + motu << " - " << nanu + motu << " = 0\n";
      cout << "24 - 0 = 24\n";
    }
  } else if (rem == 1) {
    cout << "5 * 4 = 20\n";
    cout << "20 + 3 = 23\n";
    cout << "23 + 2 = 25\n";
    cout << "25 - 1 = 24\n";
    long long int now = n / 4;
    for (long long int i = 2; i <= now; i++) {
      long long int nanu = (i - 1) * 4 + 2, motu = i * 4 + 1;
      cout << nanu << " + " << motu << " = " << nanu + motu << "\n";
      cout << nanu + 1 << " + " << motu - 1 << " = " << nanu + motu << "\n";
      cout << nanu + motu << " - " << nanu + motu << " = 0\n";
      cout << "24 - 0 = 24\n";
    }
  } else if (rem == 2) {
    cout << "6 * 5 = 30\n";
    cout << "30 - 4 = 26\n";
    cout << "26 - 3 = 23\n";
    cout << "23 - 1 = 22\n";
    cout << "22 + 2 = 24\n";
    long long int now = n / 4;
    for (long long int i = 2; i <= now; i++) {
      long long int nanu = (i - 1) * 4 + 3, motu = i * 4 + 2;
      cout << nanu << " + " << motu << " = " << nanu + motu << "\n";
      cout << nanu + 1 << " + " << motu - 1 << " = " << nanu + motu << "\n";
      cout << nanu + motu << " - " << nanu + motu << " = 0\n";
      cout << "24 - 0 = 24\n";
    }
  } else if (rem == 3) {
    cout << "7 * 6 = 42\n";
    cout << "5 * 4 = 20\n";
    cout << "42 - 20 = 22\n";
    cout << "22 + 3 = 25\n";
    cout << "25 + 1 = 26\n";
    cout << "26 - 2 = 24\n";
    long long int now = n / 4;
    for (long long int i = 2; i <= now; i++) {
      long long int nanu = (i - 1) * 4 + 4, motu = i * 4 + 3;
      cout << nanu << " + " << motu << " = " << nanu + motu << "\n";
      cout << nanu + 1 << " + " << motu - 1 << " = " << nanu + motu << "\n";
      cout << nanu + motu << " - " << nanu + motu << " = 0\n";
      cout << "24 - 0 = 24\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long int t = 1;
  while (t--) {
    solve();
  }
}
