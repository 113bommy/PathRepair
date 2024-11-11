#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  char in[3][4];
  while(cin>>in[0],in[0][0]!='0'){
    rep(i,2)cin>>in[i+1];
    bool h=false;
    rep(i,3){
      if(in[0][i]==in[1][i]&&in[1][i]==in[2][i]&&in[0][i]!='+'){cout<<in[0][i]<<endl;h=true;break;}
      else if(in[i][0]==in[i][1]&&in[i][1]==in[i][2]&&in[i][0]!='+'){cout<<in[i][0]<<endl;h=true;break}
    }
    if(!h){
      if(in[0][0]==in[1][1]&&in[1][1]==in[2][2]&&in[0][0]!='+')cout<<in[0][0]<<endl;
      else if(in[2][0]==in[1][1]&&in[1][1]==in[0][2]&&in[1][1]!='+')cout<<in[1][1]<<endl;
      else cout<<"NA"<<endl;
    }
  }


}