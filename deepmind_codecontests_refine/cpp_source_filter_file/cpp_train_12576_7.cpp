#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  int ans=0;
  int A=0,B=0,BA=0;
  rep(i,N) {
    string s;
    cin >> s;
    rep(j,s.size()-1) if(s[j]=='A' and s[j+1]=='B') ans++;
    if (s[0]=='B') B++;
    if (s.back()=='A') A++;
    if (s[0]=='B' and s.back()=='A') BA++;
  }
  if(B==BA and A=BA) A--;
  cout << ans+min(A,B) << endl;
  return 0;
}
