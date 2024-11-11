include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  string s;
  while(cin>>s){
    for(int i=0; i<s.size(); i++){
      if(s[i]!='@') putchar(s[i]);
      else {
	i++;
	int n=s[i]-'0';
	i++;
	for(int j=0; j<n; j++){
	  putchar(s[i]);
	}
      }
    }
    putchar('\n');
  }
}