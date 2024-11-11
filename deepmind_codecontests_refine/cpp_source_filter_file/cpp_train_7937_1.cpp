#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    gcd(b, a % b);
}
long long lcd(long long a, long long b) { return (a * b) / gcd(a, b); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, temp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      if (temp != i + 1) v.push_back(i + 1);
    }
    temp = 0;
    if (v.empty())
      cout << "0\n";
    else {
      for (int i = 1; i < v.size(); i++) {
        if (v[i] - v[i - 1] >= 1) temp++;
      }
      if (temp)
        cout << "2\n";
      else
        cout << "1\n";
    }
  }
  return 0;
}
