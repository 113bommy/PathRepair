#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	a*=100;
	b*=100;
	int aa=0,bb=0,cc=0,dd=;
	double conc=0;
	for(int an=0;a*an<=f;an++){
		for(int bn=0;a*an+b*bn<=f;bn++){
			for(int cn=0;a*an+b*bn+c*cn<=f;cn++){
				for(int dn=0;a*an+b*bn+c*cn+d*dn<=f;dn++){
					if(an+bn>0 && 100*(c*cn+d*dn)<=e*(a*an+b*bn)){
						if(conc<(double)(c*cn+d*dn)/(a*an+b*bn)*100){
							conc=(double)(c*cn+d*dn)/(a*an+b*bn)*100;
							aa=an;bb=bn;cc=cn;dd=dn;
						}
					}
				}
			}
		}
	}
	cout << a*aa+b*bb+c*cc+d*dd << ' ' << c*cc+d*dd << endl;
	return 0;
}
