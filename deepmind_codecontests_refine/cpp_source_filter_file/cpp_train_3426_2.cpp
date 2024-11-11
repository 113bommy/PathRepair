#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,s1,s2,s3,s,p;
int main() {
	while(1){
		s=0;
		cin>>a>>b>>c>>d>>e>>f;
		s1=a+d;
		s2=b+e;
		s3=c+f;
		if(s1+s2+s3==0){break;}
		p=min(s1,min(s2,s3))
		for(i=max(0,p-9);i<=p;i++){
			s=max(s,i+(s1-i)/3+(s2-i)/3+(s3-i)/3);
		}
		cout<<s<<endl;
	}
}