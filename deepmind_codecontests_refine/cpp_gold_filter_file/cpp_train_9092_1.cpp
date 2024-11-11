#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    bool ab = false;
    long long arr[n];
    vector<long long> v;
    vector<long long> v1;
    vector<long long> v2;
    for (int i = 0; i < n; i++) {
      long long k;
      cin >> k;
      arr[i] = k;
      if (k == 0) {
        ab = true;
      }
      if (k % 3 == 0) {
        v.push_back(k);
      } else if (k % 3 == 1) {
        v1.push_back(k);
      } else {
        v2.push_back(k);
      }
    }
    sort((v1).begin(), (v1).end(), greater<long long>());
    sort((v2).begin(), (v2).end(), greater<long long>());
    if (!ab) {
      cout << -1;
      return 0;
    }
    if (v1.size() % 3 == v2.size() % 3) {
      for (int i = 0; i < v1.size(); i++) {
        v.push_back(v1[i]);
      }
      for (int i = 0; i < v2.size(); i++) {
        v.push_back(v2[i]);
      }
    }
    if ((v1.size() % 3 == 1 && v2.size() % 3 == 2) ||
        (v1.size() % 3 == 0 && v2.size() % 3 == 1)) {
      for (int i = 0; i < v1.size(); i++) {
        v.push_back(v1[i]);
      }
      for (int i = 0; i < v2.size() - 1; i++) {
        v.push_back(v2[i]);
      }
    }
    if ((v1.size() % 3 == 2 && v2.size() % 3 == 1) ||
        (v2.size() % 3 == 0 && v1.size() % 3 == 1)) {
      for (int i = 0; i < v2.size(); i++) {
        v.push_back(v2[i]);
      }
      for (int i = 0; i < v1.size() - 1; i++) {
        v.push_back(v1[i]);
      }
    }
    if (v2.size() % 3 == 0 && v1.size() % 3 == 2) {
      if (v2.size() > 0) {
        for (int i = 0; i < v2.size() - 1; i++) {
          v.push_back(v2[i]);
        }
        for (int i = 0; i < v1.size(); i++) {
          v.push_back(v1[i]);
        }
      } else {
        for (int i = 0; i < v1.size() - 2; i++) {
          v.push_back(v1[i]);
        }
      }
    }
    if (v1.size() % 3 == 0 && v2.size() % 3 == 2) {
      if (v1.size() > 0) {
        for (int i = 0; i < v1.size() - 1; i++) {
          v.push_back(v1[i]);
        }
        for (int i = 0; i < v2.size(); i++) {
          v.push_back(v2[i]);
        }
      } else {
        for (int i = 0; i < v2.size() - 2; i++) {
          v.push_back(v2[i]);
        }
      }
    }
    sort((v).begin(), (v).end(), greater<long long>());
    if (v[0] == 0) {
      cout << 0;
      return 0;
    }
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
  }
  return 0;
}
