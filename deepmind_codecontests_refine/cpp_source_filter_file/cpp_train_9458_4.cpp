#include<bits/stdc++.h>
using namespace std;
int main(){
  string s1,s2;
  cin>>s1;
  int n=s1.size();
  for(int i=n-1;i>=0;i--){
    s2.insert(s1.substr(i,1))
      if(s2=="dream"||s2=="dreamer"||s2=="erase"||s2=="eraser"){
        s2="";
      }
  }
  if(s2=="")printf("YES");
  else printf("NO");
}