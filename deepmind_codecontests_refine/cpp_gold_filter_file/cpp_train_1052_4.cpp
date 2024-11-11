#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k;
  cin >> n >> k;
  long long sol = 0;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    long long aux;
    cin >> aux;
    total += aux;
    sol += total / k;
    total = total % k;
    if (i < n - 1 and total > aux) {
      total = 0;
      sol++;
    }
  }
  sol += total / k;
  if (total % k) sol++;
  cout << sol << endl;
}
