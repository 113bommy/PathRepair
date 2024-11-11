#include <bits/stdc++.h>
using namespace std;
int num[5];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int suma = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    num[x]++;
    suma += x;
  }
  if (suma == 1 or suma == 2 or suma == 5) {
    cout << -1 << endl;
    exit(0);
  }
  int coste = 0;
  if (num[1] >= num[2]) {
    coste += num[2];
    num[1] -= num[2];
    coste += num[1] / 3 * 2;
    num[3] += num[1] / 3;
    num[1] %= 3;
    if (num[1] == 1) {
      if (num[3] > 0)
        coste++;
      else
        coste += 2;
    } else if (num[1] == 2) {
      coste += 2;
    }
  } else {
    coste += num[1];
    num[2] -= num[1];
    coste += num[2] / 3 * 2;
    num[3] += num[2] / 3 * 2;
    num[2] %= 3;
    if (num[2] == 1) {
      if (num[4] > 0)
        coste++;
      else
        coste += 2;
    } else if (num[2] == 2) {
      coste += 2;
    }
  }
  cout << coste << endl;
}
