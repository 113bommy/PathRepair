#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >>N>>S;
	
  int ans=0;
  for(int i=1;i<N;i++){
    int k = 0;
    
    for(char c='a';c<='z';c++){
      bool left=false;
      bool right=false;
      
      for(int j=0;j<i;j++) if(S[j]==c) left=true;
      for(int j=i;j<N;j++) if(S[j]==c) right=true;
			
      if(left and right) k++;
    }
    
    if(ans<k) ans = k;
  }
	cout<<ans<<endl;
}