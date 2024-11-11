# include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,count=0,d,len;
  cin>>n>>k;
  string s;
  cin>>s;
  len=s.length();
  for(int i=0;i<len-1;i++){
    if(s[i]!=s[i+1])
      count++;
  }
  cout<<min(n-1,n-1-count+2*k)<<endl;
}
