#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  long long n, s;
  cin >> n >> s;
  if (2 * n <= s) {
    cout << "YES\n";
    for (int i = 1; i < n; i++) cout << 1 << " ";
    n--;
    cout << s - n;
    n++;
    cout << "\n" << n;
    exit(0);
  }
  cout << "NO\n";
}
