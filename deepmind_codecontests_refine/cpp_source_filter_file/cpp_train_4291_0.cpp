#include <bits/stdc++.h>
using namespace std;
int b = 0, c = 0;
int k = 0;
int n;
void solve(void) {
  cin >> n;
  string x;
  cin >> x;
  vector<int> indexB;
  vector<int> indexW;
  for (int i = 0; i < n; i++) {
    if (x[i] == 'B') {
      b++;
      indexB.push_back(i + 1);
    } else {
      c++;
      indexW.push_back((i + 1));
    }
  }
  if (b & 1 && c & 1) {
    cout << -1 << endl;
  } else if (b == 0 || c == 0)
    cout << 0 << '\n';
  else {
    if (!(b & 1) && (c & 1 || (b <= c))) {
      int i = 0;
      int m = 0;
      for (int k = 0; k < indexB.size(); k += 2)
        m = m + (indexB[i + 1] - indexB[i]);
      if (m > 3 * n) {
        cout << -1 << endl;
        return;
      }
      cout << m << '\n';
      while (i < indexB.size()) {
        for (int j = indexB[i]; j < indexB[i + 1]; j++) cout << j << ' ';
        i += 2;
      }
    } else {
      int i = 0;
      int m = 0;
      for (int k = 0; k < indexW.size(); k += 2)
        m = m + (indexW[i + 1] - indexW[i]);
      if (m > 3 * n) {
        cout << -1 << endl;
        return;
      }
      cout << m << '\n';
      while (i < indexW.size()) {
        for (int j = indexW[i]; j < indexW[i + 1]; j++) cout << j << ' ';
        i += 2;
      }
    }
  }
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
