#include <bits/stdc++.h>
using namespace std;
int arr[150005];
int check(int p1, int p2, int n) {
  if (p1 == 0 || p1 == n + 1 || p2 == 0 || p2 == n + 1) return 0;
  if ((p1 & 1) && (p1 - p2 == 1 || p2 - p1 == 1)) return 0;
  int temp = arr[p1];
  arr[p1] = arr[p2];
  arr[p2] = temp;
  int flag = 1;
  if (p1 & 1) {
    if (!(arr[p1] < arr[p1 - 1] && arr[p1] < arr[p1 + 1])) flag = 0;
  } else {
    if (!(arr[p1] > arr[p1 - 1] && arr[p1] > arr[p1 + 1])) flag = 0;
  }
  if (p2 & 1) {
    if (!(arr[p2] < arr[p2 - 1] && arr[p2] < arr[p2 + 1])) flag = 0;
  } else {
    if (!(arr[p2] > arr[p2 - 1] && arr[p2] > arr[p2 + 1])) flag = 0;
  }
  temp = arr[p1];
  arr[p1] = arr[p2];
  arr[p2] = temp;
  return flag;
}
vector<int> v;
int main() {
  int n;
  cin >> n;
  arr[0] = 160000;
  if (n & 1)
    arr[n + 1] = 160000;
  else
    arr[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    if ((i & 1) == 0) {
      if (!(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])) v.push_back(i);
    }
  }
  if (v.size() > 3) {
    cout << "0\n";
    return 0;
  }
  int count = 0;
  if (v.size() == 1) {
    for (int i = 1; i <= n; ++i) {
      if (check(v[0], i, n)) ++count;
      if ((arr[v[0] + 1] < arr[v[0]]) && check(v[0] - 1, i, n)) ++count;
      if ((arr[v[0] - 1] < arr[v[0]]) && check(v[0] + 1, i, n)) ++count;
    }
  } else if (v.size() == 2) {
    if (arr[v[0] + 1] < arr[v[0]] && check(v[1], v[0] - 1, n)) ++count;
    if (arr[v[0] - 1] < arr[v[0]] && check(v[1], v[0] + 1, n)) ++count;
    if (arr[v[1] + 1] < arr[v[1]] && check(v[0], v[1] - 1, n)) ++count;
    if (arr[v[1] - 1] < arr[v[1]] && check(v[0], v[1] + 1, n)) ++count;
    if (v[0] == v[1] - 2 &&
        (arr[v[0] - 1] < arr[v[0]] && arr[v[1] + 1] < arr[v[1]])) {
      for (int i = 1; i <= n; ++i) {
        if (i == v[0] || i == v[1]) continue;
        if (check(i, v[0] + 1, n)) ++count;
      }
    }
  } else {
    if (v[1] == v[0] + 2 && arr[v[0] - 1] < arr[v[0]] &&
        arr[v[1] + 1] < arr[v[1]]) {
      if (check(v[2], v[0] + 1, n)) ++count;
    }
    if (v[2] == v[1] + 2 && arr[v[1] - 1] < arr[v[1]] &&
        arr[v[2] + 1] < arr[v[2]]) {
      if (check(v[0], v[1] + 1, n)) ++count;
    }
  }
  cout << count << "\n";
  return 0;
}
