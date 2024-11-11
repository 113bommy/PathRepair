#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	cout << min(D,E)+min(A,min(B,C))-50 << endl;
}