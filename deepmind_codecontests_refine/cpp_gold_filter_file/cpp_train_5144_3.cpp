#include <bits/stdc++.h>
using namespace std;
int main() {
  long int k = 0;
  vector<int> v;
  int a, s;
  cin >> a >> s;
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int j = 0; j < s; j++) {
    if (v[j] > 0) {
      break;
    }
    k += -v[j];
  }
  cout << k << endl;
  return 0;
}
