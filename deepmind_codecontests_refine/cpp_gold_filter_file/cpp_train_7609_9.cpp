#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s = 0;
  int n;
  cin >> n;
  int p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  for (int i = 1; i < n; i++) {
    s += p[i] - p[i - 1] - 1;
  }
  cout << s << endl;
}
