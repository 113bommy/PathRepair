#include <bits/stdc++.h>
using namespace std;
int N;
string S;
map<string, int> mapa;
int main() {
  cin >> S;
  N = S.size();
  S = S + S;
  for (int i = 0; i < S.size(); i++) {
    string A = "";
    for (int j = i; j < N + i; j++) A = A + S[i];
    mapa[A]++;
  }
  cout << mapa.size();
}
