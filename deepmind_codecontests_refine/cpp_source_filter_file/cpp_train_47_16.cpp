#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX = 1e5;
void sujho() {
  long long int n;
  cin >> n;
  long long int maxtree = 1;
  bool felltree = true;
  long long int x;
  long long int y;
  long long int lasty = 0;
  long long int lastx = 0;
  cin >> lastx >> lasty;
  for (long long int i = 1; i < n - 1; i++) {
    cin >> x >> y;
    if (!felltree && lastx + lasty < x) {
      maxtree++;
      if (x - y > lastx + lasty) {
        maxtree++;
        felltree = true;
      }
    } else if (x - y > lastx && i < n - 1) {
      maxtree++;
      felltree = true;
    } else {
      felltree = false;
    }
    lastx = x;
    lasty = y;
  }
  if (!felltree) maxtree++;
  cout << maxtree << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  { sujho(); }
  return 0;
}
