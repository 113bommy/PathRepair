#include<stdio.h>
#include<algorithm>
using namespace std;
char in[20];
int main(){
	int a;scanf("%d",&a);
	while(a--){
		for(int i=0;i<10;i++)scanf("%s",in+i);
		int val=0;
		int ace=0;
		if(in[0]=='A'){val+=11;ace++;}
		else if(in[0]=='T'||in[0]=='J'||in[0]=='Q'||in[0]=='K'){val+=10;}
		else val+=in[0]-'0';
		if(in[1]=='A'){val+=11;ace++;}
		else if(in[1]=='T'||in[1]=='J'||in[1]=='Q'||in[1]=='K'){val+=10;}
		else val+=in[1]-'0';
		if(val>21){val-=10;ace--;}
		if(val==21){
			printf("blackjack\n");continue;
		}
		int at=2;
		while((val<17||(val==17&&ace)&&at<10){
			if(in[at]=='A'){val+=11;ace++;}
			else if(in[at]=='T'||in[at]=='J'||in[at]=='Q'||in[at]=='K'){val+=10;}
			else val+=in[at]-'0';
			if(val>21&&ace){val-=10;ace--;}
			at++;
		}
		if(val>21)printf("bust\n");
		else printf("%d\n",val);
	}
}