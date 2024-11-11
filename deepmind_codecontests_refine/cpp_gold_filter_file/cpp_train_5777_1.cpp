#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1;
int cas = 1;
int n;
void run() {
  if (n == 1 || n == 2) {
    cout << "1\n1" << endl;
  } else if (n == 3) {
    cout << "2\n1 3" << endl;
  } else if (n == 4) {
    cout << "4\n3 1 4 2" << endl;
  } else {
    cout << n << endl;
    cout << "1";
    for (int i = 3; i <= n; i += 2) cout << ' ' << i;
    for (int i = 2; i <= n; i += 2) cout << ' ' << i;
    cout << endl;
  }
}
int main() {
  while (cin >> n) run();
  return 0;
}
