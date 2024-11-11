#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main() {
  int n, v;
  cin >> n >> v;
  int a, b;
  for (int i = 0; i < n; i++) {
    bool ok = false;
    cin >> a;
    for (int j = 0; j < a; j++) {
      cin >> b;
      if (v > b && ok == false) {
        vec.push_back(i);
        ok = true;
      }
    }
  }
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) cout << vec[i] + 1 << " ";
}
