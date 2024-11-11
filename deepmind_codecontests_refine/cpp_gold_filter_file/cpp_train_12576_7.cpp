#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,j,m,c=0,ca=0,cb=0,cab=0;
  cin>>n;
  string s;
  for(i=0;i<n;i++){
	cin>>s;
    m=s.size();
    for(j=0;j<m-1;j++){
		if(s[j]=='A'&&s[j+1]=='B'){
          c++;
        }
    }
    if(s[0]=='B'&&s[m-1]!='A'){
	   cb++;
    }else if(s[m-1]=='A'&&s[0]!='B'){
       ca++;
    }else if(s[0]='B'&&s[m-1]=='A'){
	   cab++;
    }
  }

  if(cab==0){
    cout<<c+min(ca,cb)<<endl;
  }else{
    if(ca==0&&cb==0){
    cout<<c+cab-1<<endl;
    }else{
     cout<<c+cab+1+min(ca-1,cb-1)<<endl;
    }
  }
}
