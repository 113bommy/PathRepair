#include<iostream>
#include<algorithm>
using namespace std;

const long long B = 1000000007;
	
bool countOne(){
	int N, R;
	cin >> N;
	if(N==0) return false;
	cin >> R;
	int *counter = new int[N]();
	for(int r=0; r<R; r++){
		int s, t;
		cin >> s >> t;
		for(int i=t-1; i>=s; i--){
			int a = counter[i-1];
			int b = counter[i];
			if(a <= b){
				counter[i] = a;
				counter[i-1] = b+1;
			}
			else{
				counter[i] = a-1;
				counter[i-1] = b;
			}
		}
		for(int i=s+1; i<=t-1; i++){
			int a = counter[i-1];
			int b = counter[i];
			if(a <= b){
				counter[i] = a;
				counter[i-1] = b+1;
			}
			else{
				counter[i] = a-1;
				counter[i-1] = b;
			}
		}
	}
	
	long long fact = 1, index=0;
	for(int n=1; n<N; n++){
		index += counter[N-n-1]*fact;
		fact = ((n+1)*fact)%B;
		index = index%B;
	}
	cout << index << endl;
	delete[] counter;
	return true;
}

int main(){
	while(countOne()){}
	return 0;
}