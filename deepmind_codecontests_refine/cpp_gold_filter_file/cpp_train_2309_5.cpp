#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(150002);
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    values[c]++;
  }
  vector<bool> was(150001, false);
  for (int i = 1; i < values.size(); i++) {
    if (i == 1) {
      if (!was[i] && values[i + 1] < values[i] && values[i] > 1) {
        values[i + 1]++;
        values[i]--;
      } else {
        continue;
      }
    } else {
      if (i + 1 != values.size()) {
        if (values[i + 1] < values[i] && values[i] > 0) {
          values[i + 1]++;
          values[i]--;
        }
      }
      if (values[i - 1] < values[i] && values[i] > 0) {
        values[i - 1]++;
        values[i]--;
      }
    }
  }
  int answ = 0;
  for (int i = 0; i < values.size(); i++) {
    if (values[i] > 0) {
      answ++;
    }
  }
  printf("%d", answ);
  return 0;
}
