#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0

 int main()
 {
  int n;
  int ans=0;
  string s;
  cin >> n >> s;
  for(int i=1;i<s.size();i++){
  	map<char,int> P;
 		int p=0;
 		for(int j=0;j<i;j++){
 		char a=s[j];
 		P[a]=1;
 		}
  	for(int k=i;k<s.size();k++){
 		char b=s[k];
 		if(P[b]==1){
		 p++;
 		P[b]=0;
 			}
 		}
 		ans=max(ans,p);
 	}
 	cout<<ans<<endl;
    }
}