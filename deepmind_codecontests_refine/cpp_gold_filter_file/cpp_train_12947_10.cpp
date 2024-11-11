#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100100];
int brr[100100];
int con = 0;
vector<int> vec[100100];
int cal() {
  int x = -1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] != x) {
      x = arr[i];
      ++con;
      brr[con] = arr[i];
    }
  }
  brr[0] = -1;
  brr[con + 1] = -2;
  for (int i = 1; i <= con; i++) {
    if (brr[i - 1] == brr[i + 1])
      vec[brr[i]].push_back(2);
    else
      vec[brr[i]].push_back(1);
  }
  int ans = 1 << 28;
  int ind = 1;
  for (int i = 1; i <= k; i++) {
    int len = vec[i].size();
    int sum = 0;
    for (int j = 0; j < len; j++) {
      sum = sum + vec[i][j];
    }
    int y = con - sum;
    if (ans > y) {
      ans = y;
      ind = i;
    }
  }
  return ind;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  cout << cal() << endl;
  return 0;
}
