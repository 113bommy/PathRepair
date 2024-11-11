#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int two[61];
  two[0] = 1;
  for (int i = 1; i <= 60; i++) {
    two[i] = two[i - 1] * 2;
  }
  int test = 1;
  cin >> test;
  while (test--) {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> num;
    long long int mid = two[m - 1] - 1;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      long long int temp = 0;
      for (int j = (m - 1); j >= 0; j--) {
        if (s[j] == '1') {
          temp += two[m - 1 - j];
        }
      }
      num.push_back(temp);
    }
    sort(num.begin(), num.end());
    bool even = 1;
    map<int, int> ma;
    for (int i = 0; i < num.size(); i++) {
      if (even) {
        even = 0;
        ma[num[i]] = 1;
        if (mid >= num[i]) {
          mid++;
          while (ma[mid] == 1) {
            mid++;
          }
        }
      } else {
        ma[num[i]] = 1;
        if (mid <= num[i]) {
          mid--;
          while (ma[mid] == 1) {
            mid--;
          }
        }
        even = 1;
      }
    }
    for (int i = 0; i < m; i++) {
      long long int temp = two[m - 1 - i];
      if (mid >= temp) {
        mid -= temp;
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << endl;
  }
  return 0;
}
