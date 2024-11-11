#include <bits/stdc++.h>
using namespace std;
bool input = false;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n + 3];
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  int i = 1;
  int j = n;
  while (true) {
    if (m - i >= 1 && m + i <= n) {
      if (arr[m - i] == arr[m + i] && arr[m - i] == 1) sum += 2;
      i++;
    } else
      break;
  }
  if (m - i == 0) {
    for (int j = m + i; j <= n; j++)
      if (arr[j] == 1) sum++;
  } else if (m + i == n + 1) {
    for (int j = 0; j < m - i; j++) {
      if (arr[j] == 1) sum++;
    }
  }
  if (arr[m] == 1) sum++;
  cout << sum << endl;
}
