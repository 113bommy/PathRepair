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
    for (int i = 0; i < n; i++) {
      cout << n << ' ';
    }
    cout << '\n';
  }
}
