#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, arr[200000];
bool visited[200000];
int main() {
  cin >> n;
  int cnt0 = 0;
  int cntm = 0;
  int posm = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      cnt0++;
    } else if (arr[i] < 0) {
      cntm++;
      if (posm != -1) {
        if (arr[posm] < arr[i]) {
          posm = i;
        }
      } else {
        posm = i;
      }
    }
  }
  if ((cnt0 > 0) && (cntm > 0) && (cntm % 2 == 1)) {
    int last0 = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        if (last0 == -1) {
          last0 = i;
        } else {
          cout << 1 << " " << last0 + 1 << " " << i + 1 << endl;
          arr[last0] = -INF;
          last0 = i;
        }
      }
    }
    arr[last0] = -INF;
    cout << 1 << " " << last0 + 1 << " " << posm + 1 << endl;
    if (cnt0 + cntm != n) {
      arr[posm] = -INF;
      cout << 2 << " " << posm + 1 << endl;
    }
  } else if (cnt0 > 0) {
    int last0 = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        if (last0 == -1) {
          last0 = i;
        } else {
          cout << 1 << " " << last0 + 1 << " " << i + 1 << endl;
          arr[last0] = -INF;
          last0 = i;
        }
      }
    }
    if (cnt0 != n) {
      arr[last0] = -INF;
      cout << 2 << " " << last0 + 1 << endl;
    }
  } else if ((cntm > 0) && (cntm % 2 == 1)) {
    arr[posm] = -INF;
    cout << 2 << " " << posm + 1 << endl;
  }
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] != -INF) {
      if (last == -1) {
        last = i;
      } else {
        cout << 1 << " " << last + 1 << " " << i + 1 << endl;
        last = i;
      }
    }
  }
  return 0;
}
