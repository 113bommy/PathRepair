#include <bits/stdc++.h>
using namespace std;
void pv(vector<int>::iterator it, int len) {
  while (len != 0) {
    cout << *it << " ";
    len--;
    it++;
  }
  cout << "\n";
  return;
}
int main() {
  vector<int> arr;
  int n, m, temp1, temp2;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> temp1 >> temp2;
    for (int j = temp1; j <= temp2; j++) arr.push_back(j);
  }
  pv(arr.begin(), arr.size());
  int count = 1;
  int flag = 0;
  for (auto it = arr.begin(); it != arr.end(); it++) {
    if (*it == count)
      count++;
    else {
      if (*it > count) {
        cout << count << " 0\n";
        return 0;
      } else {
        int temp = count - 1;
        auto a = lower_bound(arr.begin(), arr.end(), temp);
        auto b = upper_bound(arr.begin(), arr.end(), temp);
        cout << temp << " " << b - a << "\n";
        return 0;
      }
    }
  }
  if (arr.size() == n && count == n + 1)
    cout << "OK\n";
  else {
    cout << *(arr.end() - 1) + 1 << " 0\n";
  }
  return 0;
}
