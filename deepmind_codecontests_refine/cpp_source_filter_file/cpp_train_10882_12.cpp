#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  map<int, int> m;
  vector<int> v;
  int arr[a];
  for (int x = 0; x < a; x++) {
    cin >> arr[x];
    m[arr[x]]++;
  }
  int sum = 0;
  for (int x = 1; x <= 100000; x++) {
    if (m[x] < 1) {
      if (sum + x <= b) {
        v.push_back(x);
        sum += x;
      } else {
        break;
      }
    }
  }
  cout << v.size() << endl;
  for (int x = 0; x < v.size(); x++) {
    cout << v[x] << " ";
  }
}
