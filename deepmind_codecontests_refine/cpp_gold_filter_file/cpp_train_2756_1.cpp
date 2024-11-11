#include <bits/stdc++.h>
using namespace std;
vector<int> gener(vector<int> l, int a) {
  vector<int> l2;
  for (int i = 0; i < l.size(); i++)
    if (i != a) l2.push_back(l[i]);
  return l2;
}
bool isright(vector<int> list) {
  if (list.size() == 1) {
    return true;
  }
  vector<double> list1;
  for (int i = 1; i < list.size(); i++) {
    if (list[i - 1] == 0 && list[i] == 0) {
      list1.push_back(100000.0);
      continue;
    }
    if (list[i - 1] == 0) {
      list1.push_back(1000000.0);
      continue;
    }
    list1.push_back(list[i] * 1.0 / list[i - 1]);
  }
  double b = list1[0];
  bool s = true;
  for (int i = 1; i < list1.size(); i++) {
    if (b != list1[i] && list1[i] != 100000.0) s = false;
  }
  if (s && b <= 100000.0) {
    return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  vector<int> list;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    list.push_back(a);
  }
  if (isright(list)) {
    cout << 0;
    return 0;
  }
  vector<double> list1;
  for (int i = 1; i < n; i++) {
    if (list[i - 1] == 0 && list[i] == 0) {
      list1.push_back(100000.0);
      continue;
    }
    if (list[i - 1] == 0) {
      list1.push_back(1000000.0);
      continue;
    }
    list1.push_back(list[i] * 1.0 / list[i - 1]);
  }
  vector<int> list2;
  list2.push_back(0);
  for (int i = 1; i < list1.size(); i++)
    if (list1[i] != list1[i - 1]) list2.push_back(i);
  if (list2.size() > 4) {
    cout << 2;
    return 0;
  }
  for (int i = 0; i < list2.size(); i++) {
    vector<int> list3 = gener(list, list2[i]);
    if (isright(list3)) {
      cout << 1;
      return 0;
    }
    list3 = gener(list, list2[i] + 1);
    if (isright(list3)) {
      cout << 1;
      return 0;
    }
  }
  cout << 2;
  return 0;
}
