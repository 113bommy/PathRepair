#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  string a[n];
  char arr[100][100];
  arr[83][83] = 'S';
  arr[69][69] = 'E';
  arr[84][84] = 'T';
  arr[83][69] = 'T';
  arr[69][83] = 'T';
  arr[69][84] = 'S';
  arr[84][69] = 'S';
  arr[83][84] = 'E';
  arr[84][83] = 'E';
  unordered_map<string, int> h;
  long long int cnt = 0;
  char third[k + 1];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]] = i;
  }
  for (long long int i = 0; i < n - 1; i++) {
    for (long long int j = i + 1; j < n; j++) {
      for (long long int m = 0; m < k; m++) {
        third[m] = arr[a[i][m] - '0' + 48][a[j][m] - '0' + 48];
      }
      third[k] = '\0';
      if (h.count(third) != 0) {
        if (h[third] > j) cnt++;
      }
    }
  }
  cout << cnt << endl;
}
