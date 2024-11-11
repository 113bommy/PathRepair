#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 * 100 * 2 + 1000;
int a[Maxn], place[Maxn];
int out;
int n;
void input() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    place[t] = i;
  }
}
void calc() {
  for (int i = 0; i < n - 1; i++)
    if (place[a[i]] > place[a[i + 1]]) {
      out = n - i - 1;
      break;
    }
}
void output() { cout << out << "\n"; }
int main() {
  input();
  calc();
  output();
  return 0;
}
