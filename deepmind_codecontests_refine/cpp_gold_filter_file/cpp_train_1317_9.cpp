#include <bits/stdc++.h>
using namespace std;
int N, arr[200];
string str;
int main() {
  cin >> N;
  cin >> str;
  int out = N;
  for (int j = 1; j <= (N - j); j++) {
    string s1 = str.substr(0, j);
    string s2 = str.substr(j, j);
    if (s1 == s2) out = min(out, N - j + 1);
  }
  printf("%d\n", out);
}
