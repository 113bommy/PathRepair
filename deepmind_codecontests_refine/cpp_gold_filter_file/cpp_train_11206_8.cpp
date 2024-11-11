#include <bits/stdc++.h>
using namespace std;
const int INFTY = 20000000;
const int MAX = 1000100;
const int MOD = 10000000;
void coutTab(int* tab, int n) {
  for (int i = 0; i < n; i++) {
    cout << tab[i] << " ";
  }
  cout << "\n";
}
bool was[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  if (k <= 2 && n == 1)
    cout << "Yes"
         << "\n";
  else if (k >= n)
    cout << "No"
         << "\n";
  else {
    bool ok = true;
    for (int i = 1; i < k + 1; i++) {
      if (was[n % i]) {
        ok = false;
        break;
      } else
        was[n % i] = 1;
    }
    if (ok)
      cout << "Yes"
           << "\n";
    else
      cout << "No"
           << "\n";
  }
}
