#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, l = 0, j, n, f1, f2;
  cin >> n;
  int a[n];
  char result[100001];
  stack<int> st;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << "1\nL";
  } else if (n == 2) {
    if (a[0] > a[1]) {
      cout << "2\nRL";
    } else {
      cout << "2\nLR";
    }
  } else {
    f1 = 0;
    f2 = n - 1;
    if (a[f1] > a[f2]) {
      st.push(a[f2]);
      result[l++] = 'R';
      f2--;
    } else {
      st.push(a[f1]);
      result[l++] = 'L';
      f1++;
    }
    for (;;) {
      if (st.top() < a[f1] && st.top() > a[f2]) {
        st.push(a[f1]);
        result[l++] = 'L';
        f1++;
      } else if (st.top() < a[f2] && st.top() > a[f1]) {
        st.push(a[f2]);
        result[l++] = 'R';
        f2--;
      } else if (st.top() > a[f1] && st.top() > a[f2]) {
        if (a[f1] > a[f2]) {
          st.push(a[f2]);
          result[l++] = 'R';
          f2--;
        } else {
          st.push(a[f1]);
          result[l++] = 'L';
          f1++;
        }
      } else
        break;
      if (f1 == f2) {
        if (st.top() < a[f1]) {
          st.push(a[f1]);
          result[l++] = 'L';
          break;
        } else
          break;
      }
    }
    cout << st.size();
    cout << "\n";
    for (j = 0; j < l; j++) cout << result[j];
  }
  return 0;
}
