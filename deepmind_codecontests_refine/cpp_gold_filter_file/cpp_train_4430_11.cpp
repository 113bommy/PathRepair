#include <bits/stdc++.h>
using namespace std;
int arr[105] = {2,  4,  9,  25, 49, 3,  5,  7,  11, 13,
                17, 19, 23, 25, 29, 31, 37, 41, 43, 47};
bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  vector<int> v;
  int cnt = 0;
  string s;
  for (int i = 2; i < 100; i++) {
    v.push_back(i);
  }
  long long n = 1;
  int ind = 0;
  for (int j = 0; j < 20; j++) {
    cout << arr[j] << endl;
    fflush(stdout);
    cin >> s;
    if (s == "yes" && cnt) {
      cout << "composite" << endl;
      return 0;
    }
    if (s == "yes") {
      cnt++;
      if (!prime(arr[j])) {
        cout << "composite" << endl;
        return 0;
      }
      for (int i = 0; i < v.size(); i++) {
        if (v[i] % arr[j]) {
          v.erase(v.begin() + i);
          i--;
        }
      }
    } else {
      for (int i = 0; i < v.size(); i++) {
        if (v[i] % arr[j] == 0) v.erase(v.begin() + i);
      }
    }
  }
  cout << "prime" << endl;
  return 0;
}
