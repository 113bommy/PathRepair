#include <iostream>
#include <string>
using namespace std;

int main() {
  int H,W;cin>>H>>W;
  int ans =0;
  for(int i=0;i<H;++i){
    string S;cin>>S;
    for (aut c:S)if(c=='#') ++ans;
  }
  if (ans==H+W-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
