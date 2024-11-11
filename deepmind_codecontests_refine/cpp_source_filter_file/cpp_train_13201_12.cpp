#include <bit/stdc++.h>
using namespace std

int main(){
	int N, A, B, i, P;
	int num[3] = {0, 0, 0};
	cin >> N >> A >> B;
	for(i = 0; i < N; i++){
		cin >> P;
		if(P <= A){
			num[0]++;
		}
		else if(P <= B){
			num[1]++;
		}
		else{
			num[2]++;
		}
	}
	cout >> min(num[0], min(num[1], num[2])) >> endl;
	return 0;
}