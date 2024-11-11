#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, count[102], max = 1;
  cin >> n;
  cin.get();
  char a[102][102], test[102];
  for (i = 0; i < n; i++) {
    cin.getline(a[i], 102);
    count[i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(a[i], a[j]) == 0) {
        count[i]++;
        count[j]++;
      }
      if (count[i] > max) {
        max = count[i];
      }
    }
  }
  cout << max;
  return 0;
}
