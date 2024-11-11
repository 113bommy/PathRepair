#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ar;
  vector<int> ar2(n, 0);
  vector<int> ar3(n, 0);
  for (int i = 1; i <= k + 1; ++i) {
    ar.push_back(i);
  }
  for (int i = 1; i <= k + 1; ++i) {
    cout.flush();
    cout << "? ";
    for (int j = 1; j <= k + 1; ++j) {
      if (j != i) cout << j << " ";
    }
    cout << "\n";
    int pos, val;
    cin >> pos >> val;
    ar2[pos - 1] += 1;
    ar3[pos - 1] = val;
  }
  int val1 = -1;
  int vall1 = -1;
  int val2 = -1;
  int vall2 = -1;
  for (int i = 0; i < n; ++i) {
    if (val1 == -1 && ar2[i] != 0) {
      val1 = ar2[i];
      vall1 = ar3[i];
    } else if (ar2[i] != 0) {
      vall2 = ar3[i];
      val2 = ar2[i];
    }
  }
  if (vall2 > vall1)
    cout << "! " << val2 << endl;
  else
    cout << "! " << val1 << endl;
}
