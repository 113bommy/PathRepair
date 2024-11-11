#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int aa[101] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    int pp;
    cin >> pp;
    aa[pp]++;
  }
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < aa[i]; j++) {
      cout << i << " ";
    }
  }
}
