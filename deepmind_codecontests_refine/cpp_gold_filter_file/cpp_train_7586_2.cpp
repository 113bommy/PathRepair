#include<iostream>

char *c;
int n,pm,pe,pj;

char solve(int m, int e, int j){
	char ans='C';
	if(m==100 || e==100 || j==100 || m+e>=180 || m+e+j>=240)
		ans = 'A';
	else if(m+e+j>=210 || (m+e+j>=150 && (m>=80 || e>=80)))
		ans = 'B';
	return ans;
}

int main(){
	while(true){
		std::cin >> n;
		if(!n)
			return 0;
		c = new char[n];
		for(int i=0; i<n; i++){
			std::cin >> pm >> pe >> pj;
			c[i] = solve(pm, pe, pj);
		}
		for(int i=0; i<n; i++)
			std::cout << c[i] << std::endl;
		delete[] c;
	}
	return 0;
}