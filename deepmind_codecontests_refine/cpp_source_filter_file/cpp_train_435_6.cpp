#include <bits/stdc++.h>
using namespace std;
void solve_1281B() {
  int ntest;
  cin >> ntest;
  while (ntest--) {
    std::string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); ++i) {
      int jmin = i + 1;
      for (int j = jmin; j < a.length(); ++j) {
        if (a[j] <= a[jmin]) jmin = j;
      }
      if (a[jmin] < a[i]) {
        swap(a[i], a[jmin]);
        break;
      }
    }
    if (a < b) {
      cout << a << std::endl;
    } else {
      cout << "---\n";
    }
  }
}
int main(int argc, char** argv) {
  solve_1281B();
  return 0;
}
