#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k,m,i;
	for(;cin>>n>>k,n;;){
		vector<int>vec(n);
		for(i=0;i<n;i++)vec[i]=i+1;
		i=(m-1)%vec.size();
		vec.erase(vec.begin()+i);
		for(;vec.size()>1;vec.erase(vec.begin()+i))if(i+=(k-1)%vec.size(),i>=vec.size())i-=vec.size();
		cout<<vec[0]<<endl;
	}
}