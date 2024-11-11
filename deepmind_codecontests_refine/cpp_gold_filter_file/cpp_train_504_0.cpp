#include <cstdio>
using namespace std;

typedef long long Int;

int main(){
	const int AIM = 1000000;
	int n;
	int num, per, sum;
	bool exist;
	bool comp[4001];
	Int pro[4001];
	
	while(true){
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 1; i <= 4000; i++){
			comp[i] = false;
			pro[i] = 0;
		}
		exist = false;
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &num, &per, &sum);
			if(comp[num]) continue;
			if(pro[num] + (Int)per * sum >= AIM){
				exist = true;
				comp[num] = true;
				printf("%d\n", num);
			}
			else{
				pro[num] += (Int)per * sum;
			}
		}
		if(!exist) printf("NA\n");
	}
	
	return 0;
}