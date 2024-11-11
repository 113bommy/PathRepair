#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
vector<int> a;
int ww[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int q;
      cin >> q;
      ww[q]++;
    }
  }
  for (int i = 0; i < 100; i++)
    if (ww[i] == n) a.push_back(i);
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
}
