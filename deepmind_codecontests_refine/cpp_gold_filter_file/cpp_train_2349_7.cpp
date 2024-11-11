#include <bits/stdc++.h>
using namespace std;
string l = "NO";
vector<int> a;
int k;
void dfs(int n) {
  if (n == k) {
    l = "YES";
  } else if (n > k) {
    if (n % 2 == 0) {
      n = n / 2;
      a.push_back(n);
      dfs(n);
    } else if (n % 2 == 1 && n % 10 == 1) {
      n = n / 10;
      a.push_back(n);
      dfs(n);
    }
  }
}
int main() {
  int n, i;
  cin >> k >> n;
  a.push_back(n);
  dfs(n);
  if (l == "YES") {
    cout << l << endl;
    cout << a.size() << endl;
    for (i = a.size() - 1; i >= 0; i--) cout << a[i] << " ";
    cout << endl;
  } else
    cout << l << endl;
}
