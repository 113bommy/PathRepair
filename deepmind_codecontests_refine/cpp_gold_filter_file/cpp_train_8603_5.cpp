#include <bits/stdc++.h>
using namespace std;
const long mod = 1e9 + 7;
const long long inf = 2e9 + 10;
long long powmod(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int l = 1e5 + 5;
int le1, le2;
string in;
char ou[l];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> le1 >> le2;
  cin >> in;
  int Set[28];
  for (int(i) = 0; (i) < (int)(28); ++(i)) Set[i] = 0;
  for (int(i) = 0; (i) < (int)(le1); ++(i)) Set[in[i] - 'a'] = 1;
  bool fcuk = false;
  int id;
  char chotu;
  for (int(i) = 0; (i) < (int)(26); ++(i))
    if (Set[i]) {
      chotu = i + 'a';
      break;
    }
  if (le2 <= le1) {
    for (int(i) = (int)(le2 - 1); (i) >= (int)(0); --(i)) {
      for (int(j) = (int)(in[i] - 'a' + 1); (j) <= (int)(25); ++(j)) {
        if (Set[j] == 1) {
          ou[i] = j + 'a';
          fcuk = true;
          break;
        }
      }
      if (fcuk) {
        id = i;
        break;
      }
    }
    if (fcuk) {
      for (int(i) = 0; (i) < (int)(id); ++(i)) ou[i] = in[i];
      for (int(i) = (int)(id + 1); (i) <= (int)(le2 - 1); ++(i)) ou[i] = chotu;
    } else {
      for (int(i) = 0; (i) < (int)(le1); ++(i)) ou[i] = in[i];
      for (int(i) = (int)(le1); (i) <= (int)(le2 - 1); ++(i)) ou[i] = chotu;
    }
  } else {
    for (int(i) = 0; (i) < (int)(le1); ++(i)) ou[i] = in[i];
    for (int(i) = (int)(le1); (i) <= (int)(le2 - 1); ++(i)) ou[i] = chotu;
  }
  for (int(i) = 0; (i) < (int)(le2); ++(i)) cout << ou[i];
  cout << "\n";
  return 0;
}
