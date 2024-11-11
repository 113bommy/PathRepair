#include <bits/stdc++.h>
using namespace std;
void da(int *a, int s, int e) {
  for (int i = s; i < e; i++) cout << a[i] << " ";
}
void db(string s) { cout << s << '\n'; }
void cp(int *a, int *b, int n) {
  for (int i = 0; i < n; i++) b[i] = a[i];
}
void de(int a) { cout << a << " <\n"; }
int n, m;
const long long N = 2e5 + 10, MOD = 1e9 + 7, INF = 1e15 + 10, LOG = 26, V = 107;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n == 5)
    cout << ">...v\nv.<..\n..^..\n>....\n..^.<\n1 1";
  else if (n == 3)
    cout << ">vv\n^<.\n^.<\n1 3";
  else {
    for (int i = 0; i < 50; i++) {
      cout << "v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<"
              "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
           << endl;
      cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>."
              ">.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>^"
           << endl;
    }
    cout << "1 1\n";
  }
}
