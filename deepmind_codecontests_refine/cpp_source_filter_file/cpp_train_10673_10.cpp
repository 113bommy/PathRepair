#include <bits/stdc++.h>
using namespace std;
int result[5009], answer[5009], visited[5009];
int main() {
  int n, temp, i, j;
  cin >> n;
  int arr[n + 9];
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (i = 1; i <= n; i++) {
    temp = arr[i];
    for (j = 1; j <= n; j++) {
      answer[j] = 0;
    }
    for (j = i; j <= n; j++) {
      if (j == i) {
        result[arr[j]]++;
        answer[arr[j]]++;
      } else {
        answer[arr[j]]++;
        if (arr[j] > temp && answer[arr[j]] == answer[temp]) {
          result[temp]++;
        } else if (temp == arr[j]) {
          result[arr[j]]++;
          temp = arr[j];
        } else if (arr[j] > temp && answer[arr[j]] > answer[temp]) {
          result[arr[j]]++;
          temp = arr[j];
        } else if ((arr[j] < temp && answer[arr[j]] >= answer[temp])) {
          result[arr[j]]++;
          temp = arr[j];
        } else if ((arr[j] < temp && answer[arr[j]] < answer[temp])) {
          result[temp]++;
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (visited[i] != 1) {
      visited[i] = 1;
      cout << result[i] << " ";
    } else
      cout << "0 ";
  }
}
