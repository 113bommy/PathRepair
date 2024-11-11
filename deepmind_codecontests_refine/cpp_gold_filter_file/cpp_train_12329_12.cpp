#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string x;
  cin >> n >> x;
  long long c = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == 'B') c += pow(2, i);
  }
  cout << c << endl;
}
