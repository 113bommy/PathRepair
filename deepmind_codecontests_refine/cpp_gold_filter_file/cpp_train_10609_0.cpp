#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, Q, M, temp;
	
	while(1){
		int temp2[300] = {}, ans = 0;
		cin>>N>>Q;
		
		if(N == 0 && Q == 0) break;
		
		for(int i = 1; i <= N; i++){
			cin>>M;
			for(int j = 1; j <= M; j++){
				cin>>temp;
				temp2[temp]++;
			}
		}
		
		for(int i = 1; i <= 250; i++){
			if(temp2[ans] < temp2[i])ans = i;
		}
		
		if(temp2[ans] >= Q) cout<<ans<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
