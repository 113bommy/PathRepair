#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W, N;cin>>H>>W>>N;
  int r, c;cin>>r>>c;
  string S, T;cin>>S>>T;

  int left=0, right=W+1;
  int upper=0, lower=H+1;
  bool ans=true;

  if(S[N-1]=='L') left++;
  if(S[N-1]=='R') right--;
  if(S[N-1]=='U') upper++;
  if(S[N-1]=='D') lower--;

  for (int i=N-2;i>=0;--i){
    if(T[i]=='R') left=max(0, left-1);
    if(T[i]=='L') right=min(W+1, right+1);
    if(T[i]=='D') upper=max(0, upper-1);
    if(T[i]=='U') lower=min(H+1, lower+1);

    if(S[i]=='L') left++;
    if(S[i]=='R') right--;
    if(S[i]=='U') upper++;
    if(S[i]=='D') lower--;

    if(left+1=>right) ans=false;
    if(upper+1=>lower) ans=false; 
  }

  if(left>=c||right<=c|| upper>=r|| lower<=r) ans=false;

  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}