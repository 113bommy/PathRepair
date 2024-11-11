#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mi = 0;
  bool a[101] = {false};
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    a[j] = true;
    mi = max(mi, j);
  }
  if (a[1]) {
    cout << "1";
    return 0;
  }
  n = 0;
  for (int i = 2; i <= sqrt(mi); i++) {
    if (a[i]) {
      for (int j = i + i; j <= mi; j += i) a[j] = false;
    }
  }
  for (int i = 2; i <= mi; i++)
    if (a[i]) n++;
  cout << n;
}
