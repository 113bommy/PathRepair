#include<stdio.h>
#include<iostream>
char map[8][9];
int start[2];
void explosion(int x,int y){
	int ai;
	map[x][y]='0';
	int j,k;
	for(i=-3;i<4;i++){
		if((x+i>=0)&&(x+i<9)&&(map[x+i][y]=='1')){
			explosion(x+i,y);
		}
		if((y+i>=0)&&(y+i<9)&&(map[x][y+i]=='1')){
			explosion(x,y+i);
		}
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<n+1;i++){
		for(j=0;j<8;j++){
			scanf(" %s",&map[j]);
		
		scanf("%d %d",&start[0],&start[1]);
		if(map[start[1]-1][start[0]-1]=='1')explosion(start[1]-1,start[0]-1);
		printf("Data %d:\n",i);
		for(j=0;j<8;j++){
			for(k=0;k<8;k++){
				putchar(map[j][k]);
			}
			printf("\n");
		}
	}
}