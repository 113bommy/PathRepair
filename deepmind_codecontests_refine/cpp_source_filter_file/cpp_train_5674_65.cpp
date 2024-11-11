#include <bits/stdc++.h>
using namespace std;
pair<long long, long long>* pa;
long long s[100002], arr[102][102], arr1[100002];
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  long long mx = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] > mx) {
        mx = arr[i][j];
        arr1[i] = j + 1;
      }
    }
    mx = 0;
  }
  for (int i = 0; i < m; i++) {
    s[arr1[i]]++;
  }
  int b = 0;
  mx = 0;
  for (int i = 0; i < n + 1; i++) {
    if (s[i] > mx) {
      mx = s[i];
      b = i;
    }
  }
  cout << b << endl;
}
