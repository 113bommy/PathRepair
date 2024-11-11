#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int c = 1;
    for (int j = 1; j < n; j++) {
      if (v[i] < v[j]) c++;
    }
    cout << c << " ";
  }
}
