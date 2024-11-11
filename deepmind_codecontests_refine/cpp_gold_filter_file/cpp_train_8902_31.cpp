#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  const int RIBBON_SIZE = 100001;
  int a[RIBBON_SIZE];
  bool is_visited[RIBBON_SIZE] = {false};
  char c;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    if (c == '<')
      a[i] = -1;
    else
      a[i] = 1;
  }
  int value;
  for (int i = 1; i <= n; i++) {
    cin >> value;
    a[i] *= value;
  }
  int pos = 1;
  while (1 <= pos && pos <= 100000 && !is_visited[pos]) {
    is_visited[pos] = true;
    pos += a[pos];
  }
  if (pos < 1 || pos > n)
    cout << "FINITE" << endl;
  else
    cout << "INFINITE" << endl;
  return 0;
}
