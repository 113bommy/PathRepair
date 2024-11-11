#include <bits/stdc++>
using namespace std;

int main(){
	int n, i;
	double a, sum, c, average;

	for(;;){
		int s[1001]={};
		sum = 0;
		cin >> n;
		if(n == 0)
		break;

		for(i = 0;i < n;i++){
			cin >> s[i];
			sum += s[i];
		}
		average = (double)sum / n;
		sum = 0;

		for(i = 0;i < n;i++)
			sum += pow(s[i] - average,2);

			c = (double)sum / n;
			a = sqrt(c);

			printf("%7lf\n", a);
		}
	return 0;
}