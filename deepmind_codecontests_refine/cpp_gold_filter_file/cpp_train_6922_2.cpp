#include <bits/stdc++.h>
using namespace std;
int main() {
  long long na, nb;
  cin >> na >> nb;
  long long k, m;
  cin >> k >> m;
  long long a1[na], a2[nb];
  long long i;
  for (i = 0; i < na; i++) {
    cin >> a1[i];
  }
  for (i = 0; i < nb; i++) {
    cin >> a2[i];
  }
  sort(a1, a1 + na);
  sort(a2, a2 + nb);
  if (a1[k - 1] < a2[nb - m]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
