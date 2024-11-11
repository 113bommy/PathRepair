#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> report(n);
  int posCount = 0;
  int negCount = 0;
  for (int i = 0; i < n; i++) {
    cin >> report[i];
    if (report[i] >= 0) {
      posCount++;
    } else {
      negCount++;
    }
  }
  if (posCount == n) {
    cout << 1 << endl;
    cout << n << endl;
    return 0;
  }
  if (negCount <= 2) {
    cout << 1 << endl;
    cout << n << endl;
    return 0;
  }
  int neg = 0;
  int folders = 0;
  int partitions = 0;
  vector<int> item;
  for (int i = 0; i < report.size(); i++) {
    folders++;
    if (report[i] < 0) {
      neg++;
      if (neg == 3) {
        item.push_back(--folders);
        i--;
        partitions++;
        folders = 0;
        neg = 0;
      }
    }
  }
  if (folders != 0) {
    item.push_back(folders);
  }
  cout << partitions << endl;
  for (auto x : item) {
    cout << x << ' ';
  }
  cout << endl;
}
