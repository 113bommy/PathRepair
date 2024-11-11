#include<string>
#include<iostream>
#include<cmath>
using namespace std;
long long bit(int l,int r,int po){
	if(l>r)
	return 0;
	long long cnt=0;
	for(int i=l;i<=r;i++)
	cnt+=(1<<i)*pow(10,po+l-i);
	return cnt;
}
int main(){
	string a;
	cin>>a;
	long long ans=0;
	for(int i=0;i<a.size();i++){
		ans+=((int)a[i]-'0')*((1<<i)*pow(10,a.size()-i-1)+bit(i,a.size()-2,a.size()-i-2));
	}
	cout<<ans;
}  