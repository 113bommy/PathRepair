#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
typedef complex<double> P;

int n;
double x1,Y1,x2,y2,x3,y3,x4,y4,x5,y5;

double cr(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

int naibu(P a,P b,P c,P p){
	return cr(p-a,b-a)>0&&cr(p-b,c-b)>0&&cr(p-c,a-c)>0||cr(p-a,b-a)<0&&cr(p-b,c-b)<0&&cr(p-c,a-c)<0;
}

int main(){
	cin>>n;
	while(cin>>x1>>Y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5){
		P a=P(x1,Y1),b=P(x2,y2),c=P(x3,y3),d=P(x4,y4),e=P(x5,y5);
		cout<<(naibu(a,b,c,d)^naibu(a,b,c,e)?"OK":"NG")<<endl;
	}
}