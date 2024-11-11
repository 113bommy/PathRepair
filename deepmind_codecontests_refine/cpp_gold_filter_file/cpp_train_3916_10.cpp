#include <bits/stdc++.h>
using namespace std;
int cmpfunc(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int arr[110], counter[10];
int main() {
  int n, k, i, four = 0, two = 0, one = 0;
  cin >> n >> k;
  four = n, two = 2 * n, one = 0;
  for (i = 0; i < k; i++) cin >> arr[i];
  for (i = 0; i < k; i++) {
    while (arr[i] >= 3) {
      if (four) {
        four--;
        arr[i] = arr[i] - 4;
      } else if (two) {
        two--;
        arr[i] = arr[i] - 2;
      } else {
        cout << "NO";
        return 0;
      }
    }
    if (arr[i] > 0) counter[arr[i]]++;
  }
  while (counter[2]) {
    if (four) {
      counter[2]--;
      four--;
      one++;
    } else if (two) {
      two--;
      counter[2]--;
    } else {
      counter[2]--;
      counter[1] = counter[1] + 2;
    }
  }
  if (one + two + four * 2 < counter[1])
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
