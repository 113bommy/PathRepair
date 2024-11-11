#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  string s[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  getchar();
  vector<int> v;
  for (int i = 0; i < n; i++) {
    string b;
    getline(cin, b);
    int count = 0;
    for (int j = 0; j < b.length(); j++) {
      if (b[j] == 'a' || b[j] == 'e' || b[j] == 'i' || b[j] == 'o' ||
          b[j] == 'u' || b[j] == 'y') {
        count++;
      }
    }
    v.push_back(count);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > v[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
