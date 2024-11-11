#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, q, l, m, i;
  int cnt = 0;
  cin >> b >> q >> l >> m;
  int arr[m];
  set<int> myset;
  for (i = 0; i < m; i++) {
    cin >> arr[i];
    myset.insert(arr[i]);
  }
  long long int term = (long long int)b;
  if (b > l) {
    cout << 0 << endl;
    return 0;
  }
  if (b == 0) {
    if (myset.find(0) == myset.end()) {
      cout << "inf" << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  if (q == 0) {
    if (myset.find(0) == myset.end()) {
      cout << "inf" << endl;
      return 0;
    } else if (myset.find(b) == myset.end()) {
      cout << 1 << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  if (q == 1) {
    if (myset.find(b) == myset.end()) {
      cout << "inf" << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  if (q == -1) {
    if (myset.find(b) == myset.end() || myset.find(-b) == myset.end()) {
      cout << "inf" << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  while (abs(term) <= l) {
    if (myset.find(term) == myset.end()) {
      cnt++;
    }
    term *= q;
  }
  cout << cnt << endl;
  return 0;
}
