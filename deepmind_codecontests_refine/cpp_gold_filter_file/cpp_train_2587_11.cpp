#include <iostream>
using namespace std;

int main(){
	int K, S, a=0;
	cin >> K >> S;

	for(int X=0;X<=K;X++){
		for(int Y=0;Y<=K;Y++){
			if(S-X-Y<=K&&S-X-Y>=0) a++;
		}
	}
	cout << a ;
}