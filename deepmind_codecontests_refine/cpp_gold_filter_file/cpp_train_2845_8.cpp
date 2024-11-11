#include <bits/stdc++.h>
using namespace std;
vector<int> fact(int n) {
  vector<int> V;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      V.push_back(i);
      if (i * i != n) V.push_back(n / i);
    }
  }
  V.push_back(n);
  return V;
}
int main() {
  int n, m, i, j;
  cin >> n >> m;
  vector<bool> Z(n + 1, false);
  unordered_map<int, int> M;
  while (m--) {
    char c;
    cin >> c;
    cin >> i;
    vector<int> V = fact(i);
    if (c == '+') {
      if (Z[i])
        cout << "Already on\n";
      else {
        for (j = 0; j < V.size(); j++) {
          if (M.find(V[j]) != M.end() && M[V[j]]) break;
        }
        if (j == V.size()) {
          cout << "Success\n";
          Z[i] = true;
          for (j = 0; j < V.size(); j++) M[V[j]] = i;
        } else
          cout << "Conflict with " << M[V[j]] << endl;
      }
    } else {
      if (Z[i] == false)
        cout << "Already off\n";
      else {
        Z[i] = false;
        for (j = 0; j < V.size(); j++) M[V[j]] = 0;
        cout << "Success\n";
      }
    }
  }
}
