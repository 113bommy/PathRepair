#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int chest = 0, bicep = 0, back = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n > 0) {
    chest += a[0];
  }
  if (n > 1) {
    bicep += a[1];
  }
  if (n > 2) {
    back += a[2];
  }
  for (int i = 3; i < n; i++) {
    if (i % 3 == 0) chest += a[i];
    if ((i - 1) % 3 == 0) bicep += a[i];
    if ((i - 2) % 3 == 0) back += a[i];
  }
  if (chest > bicep && chest > back) cout << "chest" << endl;
  if (bicep > chest && bicep > back) cout << "biceps" << endl;
  if (back > chest && back > bicep) cout << "back" << endl;
  return 0;
}
