#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<long long>num;
long long n,a[10000];
int main(){
	for(int i=1;i<=9;i++){
		for(int j=i;j<=9;j++){
			string S="";
			for(int k=i;k<=j;k++)S+=(char)('0'+k);
			num.push_back(stoll(S));
		}
	}
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	int maxn=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			long long B=a[i]*a[j];
			bool flag=false;
			for(int k=0;k<num.size();k++){
				if(num[k]==B)flag=true;
			}
			if(flag==true)maxn=max(maxn,B);
		}
	}
	cout<<maxn<<endl;
	return 0;
}