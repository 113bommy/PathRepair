#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int* arr1 = new int[n];
  int* arr2 = new int[m];
  vector<int> arr3;
  vector<int> arr4;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> arr2[j];
  }
  int j = 0;
  int k = 0;
  while ((j < n) && (k < m)) {
    if ((arr1[j] - x <= arr2[k]) && (arr2[k] <= arr1[j] + y)) {
      count++;
      arr3.push_back(j + 1);
      arr4.push_back(k + 1);
      j++;
      k++;
    } else if (arr1[j] - x > arr2[k]) {
      arr1[j] > arr2[k];
      k++;
    } else if (arr1[j] + y < arr2[k]) {
      j++;
    }
  }
  cout << count << endl;
  for (int i = 0; i < k; i++) {
    cout << arr3[i] << " ";
    cout << arr4[i];
    cout << endl;
  }
  return 0;
}
