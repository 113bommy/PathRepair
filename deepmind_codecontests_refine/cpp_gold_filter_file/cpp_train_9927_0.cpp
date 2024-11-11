#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  vector<int> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  };
  int count = 0;
  int index1 = 0, index2 = 0;
  bool flag = false;
  for (int i = 1; i < n; i++) {
    if (v[i - 1] > v[i]) {
      if (flag == false) index1 = i - 1, flag = true;
      index2 = i;
    }
  }
  while (index1 > 0 && v[index1] == v[index1 - 1]) index1 = index1 - 1;
  while (index2 < n && v[index2] == v[index2 + 1]) index2 = index2 + 1;
  swap(v[index1], v[index2]);
  for (int i = 1; i < n; i++) {
    if (v[i - 1] > v[i]) {
      count++;
    }
  }
  if (count > 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
