#include <bits/stdc++.h>
using namespace std;
bool isEqual(int arr[], int brr[], int len) {
  for (int i = 0; i < len; i++) {
    if (arr[i] != brr[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string p, h;
    cin >> p >> h;
    int lp = p.length(), lh = h.length();
    if (p.length() > h.length()) {
      cout << "no" << endl;
      continue;
    }
    int orig[lp];
    for (int i = 0; i < lp; i++) {
      orig[i] = p[i] - 'a';
    }
    sort(orig, orig + lp);
    bool stop = false;
    for (int i = 0; i <= lh - lp; i++) {
      int j = i;
      int count = lp;
      int arr[lp];
      int k = 0;
      while (count--) {
        arr[k] = h[j] - 'a';
        j++;
        k++;
      }
      sort(arr, arr + lp);
      if (isEqual(arr, orig, lp)) {
        cout << "yes" << endl;
        stop = true;
        break;
      }
    }
    if (stop) {
      continue;
    } else {
      cout << "no" << endl;
    }
  }
}
