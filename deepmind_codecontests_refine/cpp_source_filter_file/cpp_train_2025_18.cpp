#include <bits/stdc++.h>
using namespace std;
int arr1[1000007];
int arr2[1000007];
int arr3[1000007];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
    arr2[i] = arr1[i];
  }
  sort(arr2, arr2 + n);
  int mini = arr2[0];
  int cnt = 0, counter = 0;
  for (int i = 0; i < n; i++) {
    if (arr2[i] == mini)
      cnt++;
    else
      break;
  }
  if (arr1[0] == mini) {
    for (int i = 0; i < n; i++) {
      if (arr1[i] == mini)
        counter++;
      else
        break;
    }
  }
  int rabby = cnt - counter;
  if (rabby == 0) {
    int pro = 1;
    for (int i = 0; i < n; i++) {
      if (arr1[i] != arr2[i]) {
        pro = 0;
        break;
      }
    }
    if (pro == 0)
      cout << "-1" << endl;
    else
      cout << "0" << endl;
  } else {
    int r = 0, save;
    for (int i = n - 1; i >= 0; i++) {
      if (arr1[i] == mini) r++;
      if (r == rabby) {
        save = i;
        break;
      }
    }
    int j = 0;
    for (int i = save; i < n; i++) arr3[j++] = arr1[i];
    for (int i = 0; i < save; i++) arr3[j++] = arr1[i];
    int pro = 1;
    for (int i = 0; i < n; i++) {
      if (arr3[i] != arr2[i]) {
        pro = 0;
        break;
      }
    }
    if (pro == 0)
      cout << "-1" << endl;
    else {
      int fin = n - save;
      cout << fin << endl;
    }
  }
  return 0;
}
