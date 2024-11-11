#include <cstdio>
#include <stack>
using namespace std;
int main(){
	int n;
	stack<int> car;
	while(~scanf("%d",&n)) {
		if(n!=0) car.push(n);
		else{
			printf("%d\n",car.top());
			car.pop();
		}
	}	
	return 0;
}