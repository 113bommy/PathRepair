#include<iostream>
#include<cctype>
#include<string>
using namespace std;
bool find(string s){
	return s.find("the",0)!=string::npos
		|| s.find("this",0)!=string::npos
		|| s.find("that",0)!=string::npos;
}
string rotate(string s,int n){
	for(int i=0;i<s.size();i++){
		if(isalpha(s[i]))s[i] = (s[i]-'a'+n)%26+'a';
	}
	return s;
}
int main(){
	string s;
	while(getline(cin,s)){
		for(int i=0;i<26;i++){
			if(find(rotate(s,i))){
				cout<<rotate(s,i)<<endl;
				break;
			}
		}
	}
	return 0;
}