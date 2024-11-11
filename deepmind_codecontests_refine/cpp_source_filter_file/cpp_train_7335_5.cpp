#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, first = 0, second = 0, LexicalGreater = 0;
  cin >> n;
  int arr[n];
  vector<int> firstArr, secondArr;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > 0) {
      first += arr[i];
      firstArr.push_back(arr[i]);
    } else {
      second += abs(arr[i]);
      secondArr.push_back(arr[i]);
    }
  }
  if (first == second) {
    for (int i = 0; i < min(firstArr.size(), secondArr.size()); i++) {
      if (firstArr[i] > abs(secondArr[i])) {
        cout << "first";
        return 0;
      } else if (firstArr[i] < abs(secondArr[i])) {
        cout << "second";
        return 0;
      }
    }
    if (arr[n - 1] > 0)
      cout << "first";
    else
      cout << "second";
  } else if (first > second) {
    cout << "first";
  } else
    cout << "second";
}
