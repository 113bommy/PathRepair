#include<iostream>
using namespace std;

int main(){
  int n,k; cin>>n >>k;
  char s[51]; 
  cin>>s;
  
  s[k-1] = s[k-1]-'A'+'a';
  cout<<s<<endl;
}