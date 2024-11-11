#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[5010];
  cin >> n;
  int mot[5010], hai[5010], ba[5010];
  int a(0), b(0), c(0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      mot[a] = i;
      a++;
    } else if (arr[i] == 2) {
      hai[b] = i;
      b++;
    } else {
      ba[c] = i;
      c++;
    }
  }
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  cout << min << endl;
  for (int i = 0; i < min; i++) {
    cout << mot[i] << " " << hai[i] << " " << ba[i] << endl;
  }
  return 0;
}
