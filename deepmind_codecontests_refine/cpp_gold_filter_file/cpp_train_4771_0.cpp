#include <bits/stdc++.h>
using namespace std;

int main(){
int a;
cin >> a;
int c=a;
for (int i=0;i<=a;i++){
  	int b=0;
	int d=i;
	while (d>0) {b+=d%6; d/=6; }
	d=a-i;
  	while (d>0){b+=d%9; d/=9;}
	if (b<=c) c=b;
}

cout <<c << endl;
  
  return 0;
}
