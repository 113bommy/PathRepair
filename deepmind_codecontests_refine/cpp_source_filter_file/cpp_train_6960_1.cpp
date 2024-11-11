#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int W,H,N;
  cin >> W >> H >> N;
  int w1=0,w2=W,h1=0,h2=H;
  int x,y,a;
  while(cin >> x >> y >> a){
    if (a==1){w1=max(w1,x);}
    if (a==2){w2=min(w2,x);}
    if (a==3){h1=max(h1,y);}
    if (a==4){h2=min(h2,y);}
  }
  if(w1>=w2 || h1>=h2){cout << 0 << emdl;}
  else{cout << (w2-w1)*(h2-h1) << endl;}
}


