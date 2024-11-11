#define	_USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <set>
#include <complex>
#include <utility>
#include <numeric>
using namespace std;
typedef pair<double,double> P;


int main(){
	
	P p[50];
	char c;
	double ans=0;
	int n=1;
	while(cin>>p[n].first>>c>>p[n].second)
		n++;

	p[n].first=p[1].first;
	p[n].second=p[1].second;
	n--;
	
	for(int i=1;i<=n;i++){
		double s=0;
		s=(p[i].first-p[i+1].first)*(p[i].second+p[i+1].second);
		ans+=s;
	}
	
	printf("%.6f\n",abs(ans)/2);
	
	
	
}