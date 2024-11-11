#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	while(true){
		vector<int> vi(3);
		for(int i=0; i<6; ++i){
			int tmp;
			cin >> tmp;
			vi[i%3]+=tmp;
		}
		bool flag=true;
		for(int i=0; i<3; ++i){
			if(vi[i]!=0) flag=false;
		}
		if(flag) break;
		int ans=0;
		for(int i=0; i<3; ++i){
			vector<int> hoge=vi;
			int sum=0;
			{
				int tmp=min(hoge[0],min(i,min(hoge[1],hoge[2])));
				for(int j=0; j<3; ++j) hoge[j]-=tmp;
				sum+=tmp;
			}
			for(int j=0; j<3; ++j){
				int tmp=hoge[j]/3;
				hoge[j]-=tmp*3;
				sum+=tmp;
			}
			ans=max(ans,sum);
		}
		cout << ans << endl;
	}
	return 0;
}