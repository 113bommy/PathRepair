#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
  cin>>n;
 set<string> s;
  while(n--){
    string s1;
    cin>>s1;
    s.insert(s1);
  }
  cout<<s.size()<<"\n";  
  return 0;
}
