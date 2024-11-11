#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n;
vector<int> correct{2, 3, 4, 5, 12, 30, 35, 43, 46, 52, 64, 86};
bool in(int x, const vector<int> &vec) {
  return binary_search(vec.begin(), vec.end(), x);
}
int main() {
  cin >> n;
  if (in(n, correct)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}
