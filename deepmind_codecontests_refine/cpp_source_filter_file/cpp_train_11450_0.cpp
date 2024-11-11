#include<iostream>
#include<cmath>
#include<vector>
#include<string>
typedef unsigned long long ull;
#define rep(i,a) for(int i=0;i<a;i++)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1);
const double inf = (int)1e8;

void solve(){
  string s;int state=0;bool used=true;
  cin>>s;
  rep(i,s.size()){
    if(s[i]=='A'){state=1;}
    if(s[i]=='Z'&&state){state=0;cout<<"AZ";used=false;}
  }
  cout<<(used?-1:"")<<endl;
}
int main(void){
  solve();
  return 0;
}