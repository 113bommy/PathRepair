#include <bits/stdc++.h>
using namespace std;
const int BufferSize = 300000;
int table[BufferSize];
int a[BufferSize];
int b[BufferSize];
int n;
int main(int argc, char *argv[]) {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) table[b[i]] = i;
  for (int i = 0; i < n; ++i) a[i] = table[a[i]];
  int index = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] > a[i + 1]) {
      index = i;
      break;
    }
  }
  cout << (n - (index + 1)) << endl;
  return 0;
}
