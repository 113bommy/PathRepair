#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> tro,hnk;
set<int>::iterator it;
int main(){
	int N,hog,ba,ta,ha;
	while(1){
		cin>>N;
		if(N==0) break;
		tro.clear();
		hnk.clear();
		for(int i=0;i<N;i++){
			cin>>hog;
			tro.insert(hog);
		}
		for(int i=1;i<=N*2;i++){
			if(tro.find(i)==tro.end()){
				hnk.insert(i);
			}
		}

		ba=ta=ha=0;
		while(1){
			//??????
			if(ba==0){
				it=tro.begin();
				ba=*it;
				tro.erase(*it);
			}
			else{
				it=tro.upper_bound(ba);
				if(it==tro.end()){
					ba=0;
				}
				else{
					ba=*it;
					tro.erase(*it);
				}
			}
			
			if(tro.empty()){
				for(it=hnk.begin();it!=hnk.end();it++){
					ha++;
				}
				break;
			}

			//??±???
			if(ba==0){
				it=hnk.begin();
				ba=*it;
				hnk.erase(*it);
			}
			else{
				it=hnk.upper_bound(ba);
				if(it==hnk.end()){
					ba=0;
				}
				else{
					ba=*it;
					hnk.erase(*it);
				}
			}
			
			if(hnk.empty()){
				for(it=tro.begin();it!=tro.end();it++){
					ta++;
				}
				break;
			}
		}
		cout<<ha<<endl<<ya<<endl;
	}
	return 0;
}