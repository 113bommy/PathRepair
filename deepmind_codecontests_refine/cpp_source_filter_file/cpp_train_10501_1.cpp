#include<iostream>
#include<cstdio>
#include<stdlib>
using namespace std;
int max(const void* x,const void* y);
int main(){
	for(;;){
		int hand[5];
		if(scanf("%d,%d,%d,%d,%d",&hand[0],&hand[1],&hand[2],&hand[3],&hand[4]) == EOF){break;}
		qsort(hand,5,sizeof(int),max);
		int f = 0;
		for(int i=0; i<5; i++){
			if(hand[i] == hand[i+1] && hand[i+1] == hand[i+2] && hand[i+2] == hand[i+3]){f = 1;i+=3;}
			else if(hand[i] == hand[i+1] && hand[i+1] == hand[i+2]){f += 2;i+=2;}
			else if(hand[i] == hand[i+1]){f += 3;i+=1;}
		}
		if(hand[0]+1 == hand[1] && hand[1]+1 == hand[2] && hand[2]+1 == hand[3] && hand[3]+1 == hand[4]){f = 10;}
		if(hand[0] == 1 && hand[1] == 10 && hand[2] == 11 && hand[3] == 12 && hand[4] == 13){f = 10;}
		if(f == 1){cout <<"four card"<<endl;}
		else if(f == 2){cout <<"three card"<<endl;}
		else if(f == 3){cout <<"one pair"<<endl;}
		else if(f == 6){cout <<"two pair"<<endl;}
		else if(f == 5){cout <<"full house"<<endl;}
		else if(f == 10){cout <<"straight"<<endl;}
		else if(f == 0){cout <<"null"<<endl;}
	}
	return 0;
}
int max(const void* x,const void* y){
	return *(int*)x - *(int*)y;
}