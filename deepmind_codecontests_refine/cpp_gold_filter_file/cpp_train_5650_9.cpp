#include <bits/stdc++.h>
using namespace std;
int n;
bool f = 0;
long long s = 0;
vector<int> a;
void get_input() {
  cin >> n;
  f = 0;
  s = 0;
  a.clear();
  for (int i = 0; i < n; i++) {
    int kom;
    cin >> kom;
    a.push_back(kom);
    s += kom;
  }
}
void solve() {
  for (int i = 0; i < n; i++) {
    if (a[i] > (s / 2)) {
      f = 1;
    }
  }
  if (f == 1) {
    cout << "T\n";
    return;
  }
  if (s % 2) {
    cout << "T\n";
  } else
    cout << "HL\n";
}
void output() {}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    get_input(), solve(), output();
  }
  return 0;
}
