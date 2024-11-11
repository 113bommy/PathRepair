#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int a=0;
  string s;
  cin>>n>>s;;
  for(int i=0;i<n-2;i++){
    if(s[i]=="A" && s[i+1]=="B" && s[i+2]=="C") a++;
  }
  cout<<a<<endl;
  
}