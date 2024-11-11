#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  n--;
  m--;
  if (a[0] == '>' && b[0] == 'v') {
    cout << "NO";
    return 0;
  }
  if (a[0] == '<' && b[0] == '^') {
    cout << "NO";
    return 0;
  }
  if (a[0] == '<' && b[n] == 'v') {
    cout << "NO";
    return 0;
  }
  if (a[0] == '>' && b[n] == '^') {
    cout << "NO";
    return 0;
  }
  if (a[n] == '<' && b[0] == 'v') {
    cout << "NO";
    return 0;
  }
  if (a[n] == '>' && b[0] == '^') {
    cout << "NO";
    return 0;
  }
  if (a[n] == '<' && b[n] == '^') {
    cout << "NO";
    return 0;
  }
  if (a[n] == '>' && b[n] == 'v') {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
