#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<(int) (n);i++)
using namespace std;
int main(){
  int64_t n,c=0;
  cin >> n;
  rep(i, n+1){
    int64_t y=n/i;
    c+=(y*(y+1)*i)/2;
  }
  cout << c << endl;
}
