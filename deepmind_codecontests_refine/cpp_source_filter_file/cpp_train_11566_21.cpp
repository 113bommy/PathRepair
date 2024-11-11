#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void slove() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int dem = 0;
  vector<int> b;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] >= a[i + 1]) {
      b.push_back(a[i]);
      dem++;
    }
  }
  dem++;
  b.push_back(a[n - 1]);
  cout << dem << endl;
  for (int i = 0; i < b.size(); i++) {
    cout << b[i] << ' ';
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  ;
  slove();
  return 0;
}
