#include <bits/stdc++.h>
using namespace std;
void Void() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  cout << a[(n - 1) / 2] << endl;
}
int main() {
  Void();
  return 0;
}
