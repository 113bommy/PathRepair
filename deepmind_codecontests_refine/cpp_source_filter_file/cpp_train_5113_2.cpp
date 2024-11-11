#include <bits/stdc++.h>
using namespace std;
int main() {
  const int task = 1055;
  const int test = 3;
  const string test_file = string(".\\tests\\") + to_string(task) +
                           string("\\") + to_string(test) + string("in.txt");
  auto& in = cin;
  long long n, s;
  in >> n >> s;
  s--;
  vector<bool> a(n);
  vector<bool> b(n);
  for (int i = 0; i < n; i++) {
    int ch;
    in >> ch;
    a[i] = ch == 1;
  }
  for (int i = 0; i < n; i++) {
    int ch;
    in >> ch;
    b[i] = ch == 1;
  }
  bool result = false;
  if (a[0]) {
    if (a[s]) {
      result = true;
    } else if (b[s]) {
      for (int i = s + 1; i < n; i++) {
        if (b[i]) {
          result = true;
          break;
        }
      }
    }
  }
  cout << (result ? "YES" : "NO");
}
