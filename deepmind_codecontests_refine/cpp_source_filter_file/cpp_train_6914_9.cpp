#include <bits/stdc++.h>
using namespace std;
int dxx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      while (a[i]) {
        cout << "RPL";
        a[i]--;
      }
    else {
      cout << 'R';
      while (a[i]) {
        cout << "PLR";
        a[i]--;
      }
    }
  }
}
