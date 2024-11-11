#include <bits/stdc++.h>
using namespace std;
set<int> a, b;
int main() {
  int n, v;
  cin >> n >> v;
  int sellers = 0;
  vector<int> vec;
  int price;
  int b;
  int counter;
  for (int i = 0; i < n; i++) {
    counter = 0;
    cin >> b;
    for (int j = 0; j < b; j++) {
      cin >> price;
      if (price < v) counter++;
    }
    if (counter >= 1) {
      sellers++;
      vec.push_back(i);
    }
  }
  cout << sellers << endl;
  if (sellers > 0) {
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i] + 1;
      if (i != vec.size() - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
