#include <bits/stdc++.h>
using namespace std;
long long int t, n, i, najmn, odp, x;
long long int tab[100003];
bool dodane;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> tab[i];
    }
    najmn = -1000000000000000003;
    for (i = 1; i < n; i++) {
      if (tab[i] < tab[i - 1]) {
        najmn = max(najmn, tab[i - 1] - tab[i]);
        tab[i] = tab[i - 1];
      }
    }
    if (najmn != -1000000000000000003) {
      odp = 0;
      x = 1;
      i = 0;
      while (odp < najmn) {
        odp += x;
        x *= 2;
        i++;
      }
    } else {
      i = 0;
    }
    cout << i << "\n";
  }
  return 0;
}
