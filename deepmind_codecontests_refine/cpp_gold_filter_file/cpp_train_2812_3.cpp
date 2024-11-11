#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> s(100000);
	vector<int> t(50000);
	int n,q,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s.begin(),s.end());
	cin>>q;
	for(int j=0;j<q;j++){
		cin>>t[j];
	}
	for(int k=0;k<q;k++){
		if(binary_search(s.begin(),s.end(),t[k])){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
