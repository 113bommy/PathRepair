#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > graph;
void solve() {
  long long n;
  cin >> n;
  string x;
  while (n--) cin >> x;
  cout << "9??>>??0\n";
  cout << "0??<>1\n";
  cout << "1??<>2\n";
  cout << "2??<>3\n";
  cout << "3??<>4\n";
  cout << "4??<>5\n";
  cout << "5??<>6\n";
  cout << "6??<>7\n";
  cout << "7??<>8\n";
  cout << "8??<>9\n";
  cout << "??<>\n";
  cout << "?0>>0?\n";
  cout << "?1>>1?\n";
  cout << "?2>>2?\n";
  cout << "?3>>3?\n";
  cout << "?4>>4?\n";
  cout << "?5>>5?\n";
  cout << "?6>>6?\n";
  cout << "?7>>7?\n";
  cout << "?8>>8?\n";
  cout << "?9>>9?\n";
  cout << "?9>>9?\n";
  cout << "?>>??\n";
  cout << ">>?\n";
}
signed main(signed argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && (string)argv[1] == "local") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    while (cin.peek() != EOF) {
      cout << "\n\n";
      solve();
    }
  } else {
    solve();
  }
}
