#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> a;
  cin >> n;
  while (n--) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  return 0;
}
