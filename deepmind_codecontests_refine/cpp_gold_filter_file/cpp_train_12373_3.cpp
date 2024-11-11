#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	int alphabet[26]={0};
	for(int i=0; i<n; i++){
		int curr[26]={0};
		string s;
		cin>>s;
		for(int j=0; s[j]; j++) curr[s[j]-'a']++;
		if(!i){
			for(int j=0; j<26; j++) alphabet[j] = curr[j];
		}
		else{
			for(int j=0; j<26; j++) alphabet[j] = min(alphabet[j],curr[j]);
		}
	}
	for(int i=0; i<26; i++){
		if(alphabet[i]){
			for(int j=0; j<alphabet[i]; j++) cout<<(char)('a'+i);
		}
	}
}