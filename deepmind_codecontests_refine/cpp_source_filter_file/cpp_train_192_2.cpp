#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,m,s,sum;
	while(cin >> n && n!=0){
		sum=0;
		int i;
		for(i=0;i<12;i++){
			cin >> m >> s;
			sum+=m-s;
			if(sum>=n){
				cout << i+1 << endl;
			break;
			}
		}
		for(i=i+1;i<12;i++){
		cin >> m >> s;
		if(sum<n)
		cout << "NA" << endl;
	}
	return 0;
}