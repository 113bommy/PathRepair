#include <iostream>
#include <vector>
using namespace std;

vector<int> ret(int v,int n){
  n-=v;
  vector<int> r(4);
  r[3]=n/500; n%=500;
  r[2]=n/100; n%=100;
  r[1]=n/50; n%=50;
  r[0]=n/10;
  return r;
}
int main(){
  int n;
  int t[] = {10,50,100,500};
  int T = 0;
  while(cin>>n,n){
    vector<int> c(4);
    for(int i=0;i<4;++i) cin >> c[i];
    int s = c[0]*10+c[1]*50+c[2]*100+c[3]*500;
    vector<int> r = ret(n,s);
    if(T) cout << endl;
    for(int i=0;i<4;++i){
      if(c[i]-r[i]>0) cout << t[i] << " " << c[i]-r[i] << endl;
    }
    ++T;
  }
  return 0;
}