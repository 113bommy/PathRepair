#include <bits/stdc++.h>
using namespace std;
map<int, int> sample;
map<int, int>::iterator it;
int main() {
  int k, i, j, x;
  char c;
  bool flag = false;
  scanf("%d", &k);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      cin >> c;
      if (c != '.') {
        x = c - '0';
        if (sample.find(x) == sample.end()) {
          sample[x] = 1;
        } else {
          sample[x]++;
        }
      }
    }
  }
  for (it = sample.begin(); it != sample.end(); it++) {
    if (it->second > 2 * k) {
      flag = false;
      break;
    } else {
      flag = true;
    }
  }
  if (flag == true) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
