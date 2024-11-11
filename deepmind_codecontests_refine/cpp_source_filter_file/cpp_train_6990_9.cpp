#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, s, d, i, j;
  cin >> a >> s;
  vector<vector<long long> > v(505, vector<long long>(505, 0));
  for (i = 0; i < a; i++) {
    for (j = 0; j < s; j++) {
      cin >> v[i][j];
    }
  }
  long long m = v[0][0];
  for (i = 1; i < s; i++) m = m ^ v[i][0];
  if (m != 0) {
    cout << "TAK" << endl;
    for (i = 0; i < a; i++) cout << 1 << " ";
    return 0;
  }
  for (i = 0; i < a; i++)
    for (j = 0; j < s; j++) {
      if (v[i][j] != v[i][0]) {
        long long k;
        cout << "TAK" << endl;
        for (k = 0; k < a; k++) {
          if (k != i)
            cout << 1 << " ";
          else
            cout << j + 1 << " ";
        }
        return 0;
      }
    }
  cout << "NIE";
}
