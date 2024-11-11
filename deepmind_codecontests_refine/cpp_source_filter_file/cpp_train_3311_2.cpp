#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int ans=0;
  for (int x=0;x<=N;++i){
    for (int y=0;y<=N;++i){
      tmp=N-R*x-G*y;
      if (tmp>=0&&tmp%B==0) ans++;
    }
  }
  cout << ans << endl;
}