#include <bits/stdc++.h>
using namespace std;
bool check(vector<string> a, vector<string> b) { return (a == b); }
int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  vector<string> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<string> c = a;
  if (c == a) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[n - 1 - j][i];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  c = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[n - 1 - i][n - 1 - j];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  c = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[j][n - 1 - i];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  c = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[i][n - 1 - j];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  c = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[n - 1 - i][j];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  c = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[n - 1 - j][n - 1 - i];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  c = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = a[j][i];
  }
  if (check(b, c)) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
