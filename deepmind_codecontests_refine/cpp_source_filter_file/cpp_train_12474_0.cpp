#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  int w;
  cin >> S >> w;
  for(int i = 0; i < N; i += w){
    cout << S.at(i);
  }
  cout << endl;
  return 0;
}