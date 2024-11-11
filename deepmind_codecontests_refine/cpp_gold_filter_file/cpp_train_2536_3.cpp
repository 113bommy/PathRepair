#include <bits/stdc++.h>
using namespace std;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string S;
  cin >> S;
  int i = 0, n = S.size();
  if (S.substr(i, 3) == "ftp") {
    cout << "ftp";
    i += 3;
  } else {
    cout << "http";
    i += 4;
  }
  cout << "://";
  do {
    cout << S[i];
    ++i;
  } while (S.substr(i, 2) != "ru");
  cout << ".ru";
  i += 2;
  if (i < n) {
    cout << "/";
    for (; i < n; ++i) {
      cout << S[i];
    }
  }
  return 0;
}
