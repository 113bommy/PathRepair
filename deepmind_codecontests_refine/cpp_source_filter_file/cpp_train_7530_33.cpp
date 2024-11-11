#include <bits/stdc++.h>
using namespace std;
char str[100010];
int N, ind;
int main() {
  cin >> str;
  N = strlen(str);
  for (char c = 'z'; c >= 'a'; c--) {
    for (int i = ind + 1; i < N; i++) {
      if (str[i] == c) {
        ind = i;
        cout << c;
      }
    }
  }
}
