#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 100;
const long long BIGINF = 2e18 + 10;
const int MAX = 2e5 + 100;
const int MMAX = 1e3 + 100;
int line[MAX];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> line[i];
  }
  sort(line, line + 1);
  cout << line[n / 2 - 1] << endl;
}
