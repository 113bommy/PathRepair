#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  vector<int> marks;
  int i, j, k;
  int p;
  int f = 0, g = 0;
  for (i = 0; i < 6; i++) {
    cin >> p;
    marks.push_back(p);
    sum = sum + marks[i];
  }
  if (sum % 2 == 1) {
    cout << "NO";
  }
  if (sum == 0) {
    cout << "YES";
  } else if (sum % 2 == 0 && sum > 0) {
    for (i = 0; i < 6; i++) {
      if (marks[i] >= (sum / 2) - 1) {
        g = 1;
      }
    }
    if (g == 1) {
      cout << "NO";
    } else {
      for (i = 2; i < 6; i++) {
        for (j = i - 1; j < i; j++) {
          for (k = j - 1; k < j; k++) {
            if (marks[i] + marks[j] + marks[k] == sum / 2) {
              f = 1;
            }
          }
        }
      }
      if (f == 1) {
        cout << "YES";
      } else
        cout << "NO";
    }
  }
  return 0;
}
