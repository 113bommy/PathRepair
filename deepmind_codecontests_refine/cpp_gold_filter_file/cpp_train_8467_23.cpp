#include <bits/stdc++.h>
using namespace std;
template <typename T>
void takearray(vector<T> &a, long long int n) {
  for (long long int i = 0; i < n; i++) {
    T y;
    cin >> y;
    a.push_back(y);
  }
}
template <typename T>
void print1d(vector<T> &a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long int n;
  cin >> n;
  string s = "I'm too stupid to solve this problem";
  if (n == 0) {
    cout << "0 0 0" << endl;
    return 0;
  }
  vector<long long int> a;
  a.push_back(0);
  a.push_back(1);
  while (a[a.size() - 1] < n) {
    a.push_back(a[a.size() - 1] + a[a.size() - 2]);
  }
  if (a.size() <= 3) {
    cout << "0 0 1" << endl;
  } else {
    cout << a[a.size() - 3] << " " << a[a.size() - 3] << " " << a[a.size() - 4]
         << endl;
  }
  return 0;
}
