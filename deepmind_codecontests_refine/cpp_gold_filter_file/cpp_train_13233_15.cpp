#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  std::vector<int> z(MAX + 1);
  int arr[n];
  int x;
  long long c = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    c += arr[i];
    z[arr[i]] += 1;
  }
  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    c -= arr[i];
    z[arr[i]] -= 1;
    if (c % 2 == 0 && c / 2 <= MAX && z[c / 2] > 0) {
      v.push_back(i + 1);
    }
    c += arr[i];
    z[arr[i]] += 1;
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  return 0;
}
