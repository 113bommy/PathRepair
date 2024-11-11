#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}
template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}
int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;
  int n, m;
  cin >> n >> m >> ws;
  vector<int> aa(m + 1, 0);
  for (int i = (0); i < (n); ++i) {
    string a, b;
    getline(cin, a);
    istringstream iss(a);
    int j = 0;
    while (getline(iss, b, ' ')) {
      if (j > 0) {
        aa[stoi(b)] = 1;
      }
      ++j;
    }
  }
  bool ok = 1;
  for (int i = (1); i < (m + 1); ++i) {
    if (aa[i] == 0) {
      ok = 0;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
