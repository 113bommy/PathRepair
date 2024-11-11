#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
char arr[N];
int main() {
  scanf("%s", arr);
  int n = strlen(arr);
  sort(arr, arr + n);
  int sum = 0, cnt = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == arr[i + 1])
      cnt++;
    else {
      sum += (cnt * cnt);
      cnt = 1;
    }
  }
  cout << sum << endl;
  return 0;
}
