#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int r = 0, g = 0, b = 0;
  for (char c : S) c == 'R' ? r++ : c == 'G' ? g++ : b++;
  long ans = 1L * r * g * b;
  for (int i = 0; i < N; i++) {
    for (int j = 1; i + j + j < N; j++) {
      if ((S.at(i) ^ S.at(i + j) ^ S.at(i + j + j)) == ('R' ^ 'G' ^ 'B')) ans--;
    }
  }
  cout << ans << "\n";
}