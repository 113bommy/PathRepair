#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n;
vector<int> v;
void go(int a) { cout << (a == 0 ? "NO" : "YES"); }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i] == 1) continue;
    if (v[i] == 2) {
      go(0);
      return 0;
    }
    int res = v[i] - 1;
    int cnt = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (v[j] < res || (v[j] == res && cnt > 0)) {
        res -= v[j];
        v.erase(v.begin() + j);
        j++;
        i--;
        cnt++;
        n--;
      }
    }
    if (res) {
      go(0);
      return 0;
    }
  }
  if (v.size() == 1)
    go(1);
  else
    go(0);
}
