#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, mex = -1;
  cin >> n >> x;
  vector<int> arr(105, 0);
  for (int i = 0; i < ((int)n); i++) {
    int aux;
    cin >> aux;
    arr[aux] = true;
  }
  for (int i = 0; i < ((int)n + 1); i++) {
    if (arr[i] == false) {
      mex = i;
      break;
    }
  }
  if (mex == x)
    cout << 0 << endl;
  else if (mex > x)
    cout << 1 << endl;
  else {
    int c = 0;
    for (int i = 0; i < ((int)x); i++) {
      if (arr[i] == false) {
        c++;
        arr[i] = true;
      }
    }
    if (arr[x]) {
      c++;
      arr[x] = false;
    }
    cout << c << endl;
  }
  return 0;
}
