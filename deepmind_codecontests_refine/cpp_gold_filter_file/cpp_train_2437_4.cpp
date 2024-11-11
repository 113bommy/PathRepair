#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> arr;
  int n;
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr.push_back(a);
  }
  int maxx = arr[0];
  int minn = arr[0];
  int min_pos = 0, max_pos = 0;
  for (int i = 0; i < n; i++) {
    if (maxx <= arr[i]) {
      maxx = arr[i];
      max_pos = i;
    }
    if (minn >= arr[i]) {
      minn = arr[i];
      min_pos = i;
    }
  }
  if (arr[0] == minn && arr[n - 1] == maxx) {
    swap(arr[0], arr[max_pos]);
  } else if (arr[0] == minn) {
    swap(arr[n - 1], arr[min_pos]);
    swap(arr[0], arr[max_pos]);
  } else if (arr[n - 1] == maxx) {
    swap(arr[0], arr[max_pos]);
    swap(arr[n - 1], arr[min_pos]);
  } else {
    swap(arr[0], arr[max_pos]);
    swap(arr[n - 1], arr[min_pos]);
  }
  if (n > 3) {
    sort(arr.begin() + 1, arr.begin() + n - 1);
  }
  for (int i = 0; i < arr.size(); i++) cout << arr.at(i) << " ";
  cout << endl;
  return 0;
}
