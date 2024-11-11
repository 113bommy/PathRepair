#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
stack<int> s;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  int k = 1;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) a[i][j] = k++;
  if (n == 1 && m == 1)
    cout << "YES"
         << "\n"
         << 1;
  else if ((n == 1 && m == 2) || (n == 1 && m == 3) || (n == 2 && m == 1) ||
           (n == 2 && m == 2) || (n == 2 && m == 3) || (n == 3 && m == 1) ||
           (n == 3 && m == 2))
    cout << "NO"
         << "\n";
  else if (n == 1 && m == 4)
    cout << "YES"
         << "\n"
         << "2 4 1 3";
  else if (n == 4 && m == 1)
    cout << "YES"
         << "\n"
         << "2\n4\n1\n3";
  else if (n == 1) {
    cout << "YES"
         << "\n";
    if (m % 2 == 0) {
      for (int i = 1; i < m; i += 2) {
        cout << i << " ";
      }
      for (int i = 2; i <= m; i += 2) {
        cout << i << " ";
      }
    } else {
      for (int i = 1; i <= m; i += 2) {
        cout << i << " ";
      }
      for (int i = 2; i < m; i += 2) {
        cout << i << " ";
      }
    }
  } else if (m == 1) {
    cout << "YES"
         << "\n";
    if (n % 2 == 0) {
      for (int i = 1; i < n; i += 2) {
        cout << i << "\n";
      }
      for (int i = 2; i <= m; i += 2) {
        cout << i << "\n";
      }
    } else {
      for (int i = 1; i <= n; i += 2) {
        cout << i << "\n";
      }
      for (int i = 2; i < m; i += 2) {
        cout << i << "\n";
      }
    }
  } else if (n == 3 && m == 3) {
    cout << "YES"
         << "\n"
         << "6 1 8"
         << "\n"
         << "7 5 3\n"
         << "2 9 4\n";
  } else if (n <= m) {
    for (int i = 0; i < n; i += 2) {
      int temp = a[i][0];
      int temp2;
      a[i][0] = a[i][m - 1];
      for (long long int j = 1; j < m; j++) {
        temp2 = a[i][j];
        a[i][j] = temp;
        temp = temp2;
      }
      temp = a[i][0];
      a[i][0] = a[i][m - 1];
      for (long long int j = 1; j < m; j++) {
        temp2 = a[i][j];
        a[i][j] = temp;
        temp = temp2;
      }
    }
    for (int j = 0; j < m; j += 2) {
      int temp = a[n - 1][j];
      int temp2;
      a[n - 1][j] = a[0][j];
      for (long long int i = n - 2; i > -1; i--) {
        temp2 = a[i][j];
        a[i][j] = temp;
        temp = temp2;
      }
    }
    cout << "YES"
         << "\n";
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  } else {
    for (int i = 0; i < m; i += 2) {
      int temp = a[0][i];
      int temp2;
      a[0][i] = a[n - 1][i];
      for (long long int j = 1; j < n; j++) {
        temp2 = a[j][i];
        a[j][i] = temp;
        temp = temp2;
      }
      temp = a[0][i];
      a[0][i] = a[n - 1][i];
      for (long long int j = 1; j < n; j++) {
        temp2 = a[j][i];
        a[j][i] = temp;
        temp = temp2;
      }
    }
    for (int j = 0; j < n; j += 2) {
      int temp = a[j][m - 1];
      int temp2;
      a[j][m - 1] = a[j][0];
      for (long long int i = m - 2; i > -1; i--) {
        temp2 = a[j][i];
        a[j][i] = temp;
        temp = temp2;
      }
    }
    cout << "YES"
         << "\n";
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
