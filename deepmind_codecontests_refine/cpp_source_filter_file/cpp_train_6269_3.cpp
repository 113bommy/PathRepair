#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, count = 0, count1 = 0, x = 0, count2 = 0;
  bool ch = 0;
  cin >> n >> m;
  int arr[100], a111[100];
  int arr2[10000];
  for (int i = 0; i <= n; i++) arr[i] = 0;
  for (int i = 0; i < m * 2; i++) {
    cin >> arr2[i];
    ++arr[arr2[i] - 0];
  }
  while (1) {
    for (int i = 0; i <= n; i++) {
      if (arr[i] == 1) {
        ch = 1;
        a111[count1++] = i;
        arr[i] = 0;
      }
    }
    if (ch == 0) {
      cout << count;
      exit(0);
    }
    if (ch == 1) {
      for (int i = 0; i < count1; i++) {
        for (int j = 0; j < m * 2; j++) {
          if (a111[i] == arr2[j]) {
            if (((j + 1) % 2) == 0) {
              if (arr[arr2[j - 1]] != 0) --arr[arr2[j - 1]];
            } else {
              if (arr[arr2[j + 1]] != 0) --arr[arr2[j + 1]];
            }
          }
        }
      }
    }
    count++;
    ch = 0;
    count1 = 0;
  }
  cout << count;
}
