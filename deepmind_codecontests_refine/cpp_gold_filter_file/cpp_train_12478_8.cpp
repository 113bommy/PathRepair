#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string s,t;
  cin >> s >> t;
  int M = 0;
  for (int i = 1; i <= N; i++){
    if (s.substr(s.size() - i,i) == t.substr(0,i)) M = i;
  }
  cout << 2 * N - M;
}