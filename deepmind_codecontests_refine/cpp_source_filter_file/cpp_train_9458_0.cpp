#include<bits/stdc++.h>
using namespace std;
string s;
string c[4] = {"maerd", "remaerd", "esare", "resare"};
int main(){
	cin>>s;
	int i=0;
	int len=s.size();
	reverse(s.begin(),s.end());
	while(i<len){
		bool flag=false;
		for(int j=0;j<4;j++){
			string tmp=substr(i,c[j].size());
			if(tmp==c[j]){
				i+=c[j].size();
				flag=true;
			}
		}
		if(!flag){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}