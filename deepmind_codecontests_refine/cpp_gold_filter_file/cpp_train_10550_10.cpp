#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 1;
  int i = 2;
  vector<int> v;
  while (true) {
    if (sum > n) break;
    v.push_back(sum);
    sum += i;
    i++;
  }
  bool haysol = false;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i; j < v.size(); j++) {
      int num = v[i] + v[j];
      if (num == n) {
        haysol = true;
        break;
      }
    }
    if (haysol) break;
  }
  if (haysol) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
