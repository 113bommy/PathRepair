#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
bool used[N];
string rez;
int main() {
  int n;
  cin >> n;
  int last0 = n, cnt = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    rez += to_string(cnt);
    rez += ' ';
    cnt++;
    used[x] = 1;
    while (used[last0]) {
      cnt--;
      last0--;
    }
  }
  rez += '1';
  cout << rez;
  return 0;
}
