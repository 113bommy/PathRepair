#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[3001];
  for (int i = 1; i < n + 1; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i < n + 1; i++) {
    if (arr[i] != i) {
      cout << i;
      return 0;
    }
  }
}
