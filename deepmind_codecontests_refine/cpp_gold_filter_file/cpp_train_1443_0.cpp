#include<iostream>
using namespace std;
#include<vector>
#include<set>

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> ans(n,0);
	long long int ansr=1;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		ans[a[i]]++;
	}
	if(n%2==1)ans[0]++;
	for(int i = 1-n%2;i<n;i+=2){
		if(ans[i]!=2){
			cout<<0<<endl;
			return 0;
		}
		if(i!=0)ansr*=2;
		ansr%=1000000007;
	}
	cout<<ansr<<endl;
	return 0;
}