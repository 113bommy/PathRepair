#include <bits/stdc++.h>
using namespace std;
void play() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  play();
  int n, c = 1, max = 1;
  string arr[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) c++;
    }
    if (max < c) {
      max = c;
    }
    c = 0;
  }
  cout << max;
  return 0;
}
