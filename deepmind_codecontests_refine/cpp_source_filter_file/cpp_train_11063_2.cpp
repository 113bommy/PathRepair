#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string s;
int t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n];
    int z, o;
    z = o = 0;
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      if (ar[i] == 0)
        z++;
      else
        o++;
    }
    if (z >= n / 2) {
      cout << n / 2 << '\n';
      for (int i = 0; i < n / 2; i++) {
        cout << 0 << ' ';
      }
    } else if (o == n / 2) {
      cout << z << '\n';
      for (int i = 0; i < z; i++) {
        cout << 0 << ' ';
      }
    } else if (o > n / 2) {
      if ((n / 2) % 2) {
        cout << n / 2 - 1 << '\n';
        for (int i = 0; i < n / 2 - 1; i++) {
          cout << 1 << ' ';
        }
      } else {
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; i++) {
          cout << 1 << ' ';
        }
      }
    }
    cout << '\n';
  }
}
