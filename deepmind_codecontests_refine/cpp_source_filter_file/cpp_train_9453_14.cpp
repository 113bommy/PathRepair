#include<bits/stdc++.h>
using namespace std;

int main(){
	char b;
	cin>>b;
  
	char s[]="ACGT";
	int i=0;
	while(b-s[i]){
		i++;
	}
  
	cout<<s[3-i]<<endl;
    return 0
}//abc122_a.復習.参考.