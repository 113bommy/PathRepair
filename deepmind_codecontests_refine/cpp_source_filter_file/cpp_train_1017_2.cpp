#include<iostream>
#include<vector>
using namespace std;
int main() {
  int n, k, s;
  cin >> n >> k >> s;
  vector<int> a(k, s);
  vector<int> b(n - k, (s + 1 % 1e9));
  for (auto x : a) cout << x << " ";
  for (auto x : b) cout << x << " ";
  cout << endl;
}