#include <bits/stdc++.h
using namespace std;

int N;
string s;
long long res;
void calc(long long p, long long q){
  long long ret = 0;
  if(p == N){
     res += q;
     return;
  }
  for(int i=p; i<N; ++i){
    ret = 10*ret + (s[i] - '0');
    calc(i+1, q+ret);
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin >> s;
  N = s.length();
  calc(0, 0);
  cout << res << "\n";
  return 0;
}
