#include<bits/stc++.h>
using namespace std;
int main()
{
  string r;
  cin>>r;
  int n=r.size();
  if(n%2){
    cout<<"No";
  }
  else{
    string t="";
    for(int i=1;i<=n/2;++i)t+="hi";
    cout<<((t==r)?"Yes":"No");
  }
  return 0;
}