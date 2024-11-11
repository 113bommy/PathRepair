#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int whileCount = 0;
  string *inputs = new string[n];
  string *originals = new string[n];
  int count = 0;
  int minCount = 100000;
  for (int i = 0; i < n; i++) {
    cin >> inputs[i];
  }
  for (int i = 0; i < n; i++) {
    originals[i] = inputs[i].substr(0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      while (inputs[i] != inputs[j]) {
        whileCount++;
        inputs[j] = inputs[j].substr(1) + inputs[j][0];
        count++;
        if (whileCount > inputs[j].size()) {
          cout << -1;
          return 0;
        }
      }
      whileCount = 0;
    }
    for (int i = 0; i < n; i++) {
      inputs[i] = originals[i];
    }
    if (count < minCount) {
      minCount = count;
    }
    count = 0;
  }
  cout << minCount;
  return 0;
}
