#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
  string s;
  int n;
  cin>>s;
  n=s.length();
  map<char,int> m;
  m.insert('p',0);
  m.insert('q',1);
  m.insert('b',2);
  m.insert('d',3);
  for(int i=0;i<n;i++){
    if((m[s[i]]^m[s[n-1-i]])!=1){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}