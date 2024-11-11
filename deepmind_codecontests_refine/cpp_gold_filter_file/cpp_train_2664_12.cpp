#include <bits/stdc++.h>
using namespace std;
int N;
string colour = "ROYGBIV";
int main() {
  cin >> N;
  for (int i = 0; i < N - N % 7; i++) cout << colour[i % 7];
  for (int i = 0; i < N % 7; i++) cout << colour[i % 4 + 3];
  return 0;
}
