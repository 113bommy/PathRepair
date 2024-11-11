#include <bits/stdc++.h>
using namespace std;
int Search[1001][1001], Target1[1001], Target2[1001], Attack = 0;
int main() {
  int Data1, Data2;
  cin >> Data1 >> Data2;
  for (int i = 0; i < Data1; i++) {
    for (int i2 = 0; i2 < Data2; i2++) {
      char Test;
      cin >> Test;
      if (Test == '*') {
        Search[i][i2] = 1, Attack++;
      }
      Target1[i] += Search[i][i2];
      Target2[i2] += Search[i][i2];
    }
  }
  for (int i = 0; i < Data1; i++) {
    for (int i2 = 0; i2 < Data2; i2++) {
      if (Search[i][i2] == 0 && Target1[i] + Target2[i2] == Attack)
        return cout << "YES" << endl << i + 1 << " " << i2 + 1, 0;
      if (Search[i][i2] == 1 && Target1[i] + Target2[i2] == Attack + 1)
        return cout << "YES" << endl << i + 1 << " " << i2 + 1, 0;
    }
  }
  cout << "NO";
  return 0;
}
