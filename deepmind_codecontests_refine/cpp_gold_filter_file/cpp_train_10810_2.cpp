#include<iostream>
#include<string>
using namespace std;
 
int main(){
 string s;
 cin>>s;
 s=s.substr(0, s.size() - 1);
 int len;
 for(len = s.size()/2;len>0;len--){
 	if(s.substr(0,len) == s.substr(len,len)){
 		break;
	 }
 }
 cout<< len * 2<<endl;
 return 0;
}