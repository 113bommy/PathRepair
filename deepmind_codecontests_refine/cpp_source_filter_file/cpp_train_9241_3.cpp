#include<iostream>
#include<string>
using namespace std;

int main(){
	int k;
  string s;
  cin>>k>>s;
  if(s.size()>k){
    s= s.sbstr(0,k)+"...";
  }
  cout<<s<<endl;
}
