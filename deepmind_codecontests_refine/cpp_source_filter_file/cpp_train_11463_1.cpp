#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  long long a, b, k, massimo, elementi = 0;
  bool p[200001];
  cin >> a >> b;
  k = (long long)floor((sqrt(8.0 * (double)(a + b) + 1.0) - 1.0) / 2.0);
  massimo = k;
  for (int i = 1; i <= k; i++) p[i] = false;
  while (massimo > 0) {
    if (massimo >= a) {
      p[a] = true;
      massimo = 0;
    } else {
      p[massimo] = true;
      a -= massimo;
      massimo--;
    }
    elementi++;
  }
  cout << elementi << "\n";
  for (int i = 1; i <= k; i++)
    if (p[i] == true) cout << i << " ";
  cout << "\n";
  cout << k - elementi << "\n";
  for (int i = 1; i <= k; i++)
    if (p[i] == false) cout << i << " ";
  cout << "\n";
  return 0;
}
