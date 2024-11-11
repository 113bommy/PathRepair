#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cout << *i << " ";
  cout << endl;
}
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int conta[20], conta2[20], n;
int main() {
  string v;
  cin >> v;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  n = v.size();
  for (int(i) = (0); (i) < (n); (i)++) conta[v[i] - '0']++;
  for (int(i) = (0); (i) < (10); (i)++) conta2[i] = conta[i];
  int best = 0;
  for (int(i) = (0); (i) < (10); (i)++)
    for (int(j) = (0); (j) < (10); (j)++)
      if ((i + j) == 10 && conta[i] && conta2[j]) {
        conta[i]--, conta2[j]--;
        int f = 1;
        for (int k = 0; k <= 4; k++) {
          f += min(conta[k], conta2[9 - k]);
          f += min(conta[9 - k], conta2[k]);
        }
        f += max(min(conta[0] - conta2[9], conta2[0] - conta[9]), 0);
        if (f > best) best = f;
        conta[i]++, conta2[j]++;
      }
  if (!best) {
    cout << v << endl;
    cout << v << endl;
    return 0;
  }
  for (int(i) = (0); (i) < (10); (i)++)
    for (int(j) = (0); (j) < (10); (j)++)
      if ((i + j) == 10 && conta[i] && conta2[j]) {
        conta[i]--, conta2[j]--;
        int f = 1;
        for (int k = 0; k <= 4; k++) {
          f += min(conta[k], conta2[9 - k]);
          f += min(conta[9 - k], conta2[k]);
        }
        f += max(min(conta[0] - conta2[9], conta2[0] - conta[9]), 0);
        if (f == best) {
          string a, b;
          for (int k = 0; k <= 4; k++) {
            while (conta[k] && conta2[9 - k]) {
              a.push_back(k + '0');
              conta[k]--;
              b.push_back(9 - k + '0');
              conta2[9 - k]--;
            }
            while (conta[9 - k] && conta2[k]) {
              a.push_back(9 - k + '0');
              conta[9 - k]--;
              b.push_back(k + '0');
              conta2[k]--;
            }
          }
          int z = min(conta[0], conta2[0]);
          conta[0] -= z;
          conta2[0] -= z;
          for (int(k) = (0); (k) < (10); (k)++)
            while (conta[k]--) a.push_back(k + '0');
          for (int(k) = (0); (k) < (10); (k)++)
            while (conta2[k]--) b.push_back(k + '0');
          reverse(a.begin(), a.end());
          reverse(b.begin(), b.end());
          a.push_back(i + '0');
          b.push_back(j + '0');
          while (z--) a.push_back('0'), b.push_back('0');
          cout << a << endl;
          cout << b << endl;
          return 0;
        }
        conta[i]++, conta2[j]++;
      }
  return 0;
}
