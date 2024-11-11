#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n,a,b,c,d;
  string s;
  cin>>n>>a>>b>>c>>d;
  cin>>s;
  for(int i=a-1;i<c-1;i++)
    {
    	if(s[i]=='#'&&s[i+1]=='#'){
    		cout<<"No"<<endl;
    		return 0;
    	}
    }
  for(int i=b-1;i<d-1;i++)
    {
    	if(s[i]=='#'&&s[i+1]=='#'){
    		cout<<"No"<<endl;
    		return 0;
    	}
    } 
   if(c<d)
   {
   	  cout<<"Yes"<<endl;
   	  return 0;
   }
   for(int i=b-1;i<=d-1;i++){
   	  if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.')
   	  {
   	  cout<<"Yes"<<endl;
   	  return 0;
     }
   }
   	cout<<"No"<<endl;
	return 0;
}
