#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      s++;
    }
  }
  int c[n];
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      c[i] = -1;
    } else {
      c[i] = 1;
    }
  }
  int m_s = INT_MIN;
  int m = 0;
  for (int i = 0; i < n; i++) {
    m = m + c[i];
    if (m > m_s) {
      m_s = m;
    }
    if (m < 0) {
      m = 0;
    }
  }
  cout << m + m_s;
  return 0;
}
