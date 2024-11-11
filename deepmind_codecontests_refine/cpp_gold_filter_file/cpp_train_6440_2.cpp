#include<iostream>
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	
	char x;
	int in = 1, out = 1;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x == 'a' && in+out-2 < a+b){
			cout << "Yes" << endl;
			in++;
		}else if(x == 'b' && in+out-2 < a+b && out <= b){
			cout << "Yes" << endl;
			out++;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}