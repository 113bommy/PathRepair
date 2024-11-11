#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[200005] = {0};
  vector<int> v2, v3;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i < 200005; i++) {
    if (a[i] > 2) {
      cout << "NO"
           << "\n";
      return 0;
    }
    if (a[i] > 0) {
      v2.push_back(i);
      a[i]--;
    }
  }
  for (int i = 0; i < 200005; i++) {
    if (a[i] > 0) {
      v3.push_back(i);
      a[i]--;
    }
  }
  cout << "YES"
       << "\n";
  if (v2.size() == 0) {
    cout << 0 << "\n"
         << "\n";
  } else {
    cout << v2.size() << "\n";
    for (int i = 0; i < v2.size(); i++) {
      cout << v2[i] << " ";
    }
  }
  cout << "\n";
  if (v3.size() == 0) {
    cout << 0 << "\n"
         << "\n";
  } else {
    cout << v3.size() << "\n";
    for (int i = v3.size() - 1; i >= 0; i--) {
      cout << v3[i] << " ";
    }
  }
  return 0;
}
