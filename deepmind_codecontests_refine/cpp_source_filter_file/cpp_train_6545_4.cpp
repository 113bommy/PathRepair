#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int num;
double w, h, BMI;
char cnm;

double BMIk(double w, double h){
	double ans = w / pow(h, 2);
	return ans;
}

int main(){
	while(cin >> num >> cnm >> w >> cnm >> h){
		BMI = BMIk(w, h);
		if(BMI >= 25){
			cout << num < endl;
		}
	}
	return 0;
}