#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> v;
  if (n == 1) {
    if (s == 1) {
      cout << "NO" << endl;
    }
    if (s > 1) {
      cout << "YES" << endl;
      cout << s << endl;
      cout << 1 << endl;
    }
  }
  if (n > 1) {
    for (int i = 0; i < n - 1; i++) {
      v.push_back(1);
    }
    int el = s - (n - 1);
    v.push_back(el);
    vector<int> v1;
    for (int i = 2; i <= s - 1; i++) {
      if (i != v[v.size() - 1]) {
        v1.push_back(i);
      }
    }
    int i = 0;
    int num = 0;
    for (; i < v1.size(); i++) {
      if (v1[i] > (v.size() - 1) and v1[i] < v[v.size() - 1]) {
        num = v1[i];
        break;
      }
    }
    if (i < v1.size()) {
      cout << "YES" << endl;
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
      cout << endl;
      cout << num << endl;
    }
    if (i >= v1.size()) {
      cout << "NO" << endl;
    }
  }
}
