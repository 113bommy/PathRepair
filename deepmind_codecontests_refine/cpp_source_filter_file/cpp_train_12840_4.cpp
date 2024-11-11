#include <bits/stdc++.h>
using namespace std;
int sumc[100000];
int main() {
  int n, counter = 0, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    sumc[i] = sumc[i - 1] + m;
  }
  for (int i = 0; i < n - 1; i++) {
    if (sumc[i] = sumc[n] - sumc[i]) counter++;
  }
  cout << counter << endl;
  return 0;
}
