#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int res = a + b;
  int pref = 0;
  vector<int> vec;
  for (int i = 1;; i++) {
    if (pref + i < res) {
      vec.push_back(i);
      pref += i;
    } else
      break;
  }
  vector<int> vec1, vec2;
  int pref1 = 0;
  for (int i = vec.size() - 1; i >= 0; i--) {
    if (pref1 + vec[i] <= a) {
      vec1.push_back(vec[i]);
      pref1 += vec[i];
    } else
      vec2.push_back(vec[i]);
  }
  cout << vec1.size() << endl;
  for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << ' ';
  cout << endl;
  cout << vec2.size() << endl;
  for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << ' ';
  cout << endl;
}
