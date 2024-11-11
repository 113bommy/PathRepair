#include <iostream>
using namespace std;

#define f(i) for(int i=0; i<10; ++i)


//0008
int main(){
	int x;

	while(cin >> x){
		int a,b,c,d;
		int count=0;

		f(a)f(b)f(c)f(d){
			if(a+b+c+d == x){
				++count;
			}
		}
		cout << count <<endl;
	}
	return 0;
}