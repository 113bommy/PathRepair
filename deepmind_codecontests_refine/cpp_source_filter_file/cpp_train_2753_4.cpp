#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
const double EPS = 1e-9;
const double PI = acos(-1.0);
void printSet(int a) {
  cout << "set:  ";
  for (int i = 12; i >= 0; i--) {
    if (a & (1 << i)) cout << (12 - i) << "  ";
  }
  cout << endl;
}
int main() {
  int i, j, k;
  vector<vector<int> > ans, ans2;
  vector<int> aux, aux2, aux3;
  aux.push_back(1 << (12 - 1));
  ans.push_back(aux);
  int N;
  cin >> N;
  for (i = 2; i <= N; i++) {
    vector<vector<int> > ans2;
    int a = 1 << (12 - i);
    int last = 0;
    for (j = 0; j < ans.size(); j++) {
      aux = ans[j];
      if ((j % 2) == 1) {
        aux3 = aux;
        aux3[last] |= a;
        ans2.push_back(aux3);
        for (k = 0; k < aux.size(); k++) {
          if (k == last) continue;
          aux3 = aux;
          aux3[k] |= a;
          ans2.push_back(aux3);
        }
        aux.push_back(a);
        ans2.push_back(aux);
      } else {
        aux3 = aux;
        aux3.push_back(a);
        ans2.push_back(aux3);
        int last1 = 0;
        last = 0;
        if (j + 1 != ans.size()) {
          aux2 = ans[j + 1];
          last = -1;
          for (int k1 = 0; k1 < aux.size(); k1++) {
            for (int k2 = 0; k2 < aux2.size(); k2++) {
              if ((aux[k1] & aux2[k2]) == aux2[k2] && aux[k1] != aux2[k2] &&
                  __builtin_popcount(aux2[k2]) + 1 ==
                      __builtin_popcount(aux[k1])) {
                last = k2, last1 = k1;
              } else if ((aux[k1] & aux2[k2]) == aux[k1] &&
                         aux[k1] != aux2[k2] &&
                         __builtin_popcount(aux2[k2]) ==
                             __builtin_popcount(aux[k1]) + 1) {
                last = k2, last1 = k1;
              }
            }
          }
          if (last == -1)
            while (1)
              ;
        }
        for (k = 0; k < aux.size(); k++) {
          if (k == last1) continue;
          aux3 = aux;
          aux3[k] |= a;
          ans2.push_back(aux3);
        }
        aux3 = aux;
        aux3[last1] |= a;
        ans2.push_back(aux3);
      }
    }
    ans = ans2;
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) {
    sort(ans[i].begin(), ans[i].end());
    reverse(ans[i].begin(), ans[i].end());
    vector<int> aux = ans[i];
    int ff = 1;
    for (j = 0; j < aux.size(); j++) {
      if (j) cout << ",";
      cout << "{";
      int first = 1;
      for (k = 11; k >= 0; k--) {
        if (aux[j] & (1 << k)) {
          if (first)
            first = 0;
          else
            cout << ",";
          cout << (12 - k);
        }
      }
      cout << "}";
    }
    cout << endl;
  }
  return 0;
}
