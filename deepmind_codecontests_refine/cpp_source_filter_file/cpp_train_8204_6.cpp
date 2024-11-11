#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >>n>>s;	
  int ans=0;
  for(int i=1;i<n;i++){
    int co = 0;  
    for(char c='a';c<='z';c++){
      bool left=false;
      bool right=false;      
      for(int j=0;j<i;j++) if(s[j]==c) left=true;
      for(int j=i;j<N;j++) if(s[j]==c) right=true;			
      if(left and right) co++;
    }    
    if(ans<co) ans = co;
  }
	cout<<ans<<endl;
}
