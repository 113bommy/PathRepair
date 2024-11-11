#include <bits/stdc++.h>
using namespace std;

string s,t;

int main(){
t="AKIHABARA";
cin>>s;
  int n=s.size();
int ind=0;
for(char c:t){
  if(ind==n||s[ind]!=c){

  if(c!='A'){
    cout << "NO"<<endl;
    return 0;
  }
  }else{
  ++ind;
  }
}
if(ind!=n){
cout<<"NO"<<endl;
return 0;
}
cout<<"YES"<<endl;
return 0;
}
