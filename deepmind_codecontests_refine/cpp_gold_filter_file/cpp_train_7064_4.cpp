#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='C') l=1;
		if (s[i]=='F' && l==1){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}