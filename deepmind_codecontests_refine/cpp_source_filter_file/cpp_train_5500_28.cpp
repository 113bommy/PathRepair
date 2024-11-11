#include <iostream>
using namespace std;

int N, A ;

main(){
	cin >> N >> A ;
	cout << ( N % 500 <= A)? "Yes" : "No"  << endl;
}