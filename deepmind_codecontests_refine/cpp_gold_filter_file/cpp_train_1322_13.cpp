#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int mx = max(a, b);
  int top = 7 - mx;
  switch (top) {
    case 1: {
      cout << "1/6\n";
      break;
    }
    case 2: {
      cout << "1/3\n";
      break;
    }
    case 3: {
      cout << "1/2\n";
      break;
    }
    case 4: {
      cout << "2/3\n";
      break;
    }
    case 5: {
      cout << "5/6\n";
      break;
    }
    case 6: {
      cout << "1/1\n";
      break;
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
