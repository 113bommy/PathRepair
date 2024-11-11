#include <bits/stdc++.h>
using namespace std;
const int ar = 100000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  char arr[100][100];
  for (int w = 0; w < x; w++) {
    for (int i = 0; i < y; i++) {
      cin >> arr[w][i];
    }
  }
  int co = 0;
  for (int w = 0; w < x; w++) {
    for (int i = 0; i < y; i++) {
      for (int f = 0; f < y; f++) {
        if (arr[w][f] == arr[w][i]) {
          co++;
        }
      }
      for (int j = 0; j < x; j++) {
        if (arr[j][i] == arr[w][i]) {
          co++;
        }
      }
      if (co == 2) {
        cout << arr[w][i];
      }
      co = 0;
    }
  }
  cout << endl;
  return 0;
}
