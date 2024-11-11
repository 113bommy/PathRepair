#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> P;
const int pmax=1299709;
bool iscomp[pmax+1];
void init()
{
	P.reserve(100000);
	for(int i=2;i<pmax+1;i++){
		if(iscomp[i])continue;
		P.push_back(i);
		for(int j=2;i*j<pmax+1;j++)
			iscomp[i*j]=true;
	}
}
int main()
{
	init();
	while(true){
		int n;
		cin>>n;
		if(n==0)return 0;
		int pos=lower_bound(P.begin(),P.end(),n)-P.begin();
		if(P[pos]==n)cout<<0<<endl;
		else{
			cout<<P[pos]-P[pos-1]<<endl;
		}
	}
}