#include<iostream>

using namespace std;

struct P
{
	int x,y;
};

P maxP(const P a,const P b){
	int la=a.x*a.x+a.y*a.y;
	int lb=b.x*b.x+b.y*b.y;

	if(la>lb)return a;
	if(la<lb)return b;

	if(a.x>b.x)
		return a;
	else
		return b;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		P d,p={0,0},m={0,0};
		while(cin >> d.x >> d.y, d.x|d.y){
			p.x+=d.x;p.y+=d.y;
			m=maxP(m,p);
		}
		cout m.x << " " << m.y << endl;
	}

	return 0;
}