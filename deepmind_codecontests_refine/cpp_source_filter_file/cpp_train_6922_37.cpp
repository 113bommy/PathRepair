#include <bits/stdc++.h>
using namespace std;
void setup();
int main() {
  setup();
  int na, nb, k, m;
  cin >> na >> nb >> k >> m;
  int a[na];
  int b[nb];
  for (int i = 0; i < na; i++) {
    cin >> a[i];
  };
  for (int i = 0; i < nb; i++) {
    cin >> b[i];
  };
  if (a[k - 1] >= b[nb - 1])
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
void setup() { ios_base::sync_with_stdio(false); }
