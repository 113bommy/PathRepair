#include<iostream>
#include<string>
using namespace std;
int main() {
  string S,T;
  cin >> S >> T;
  int ans = 2000000000,t;
  int i,j;
  for(i=0;i<=S.length()-T.length();i++) {
    t = 0;
    for(j=0;j<T.length();j++) {
      if(S[i+j] != T[j])t++;
    }
    ans = min(ans,t);
  }
  cout << ans << endl;
}