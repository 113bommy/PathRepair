#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long n,s=0,min=0,max=0,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(i==0){min=a;max=a;}
		s+=a;
		if(min>a)min=a;
		if(max<a)max=a;
	}
	cout<<min<<" "<<max<<" "<<s<<endl;
    return 0;
}