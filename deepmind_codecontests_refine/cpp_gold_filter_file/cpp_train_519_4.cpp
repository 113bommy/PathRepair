#include <stack>
using namespace std;

struct Rectangle {
  int height;
  int pos;
};
 

#include <stdio.h>
#define SIZ 1400
int m[SIZ+1][SIZ+1];
int st[SIZ];
char z[9999999];
int get(){
	static int input_count=0;
	int r=0;
	for(;'0'<=z[input_count]&&z[input_count]<='9';)r=r*10+z[input_count++]-'0';
	input_count++;
	return r;
}
int main(){
	fread(z,1,sizeof(z),stdin);
	int i,j,k,y=get(),x=get(),r,ptr;
	for(j=0;j<y;j++)for(r=i=0;i<x;m[j][i]=r,i++){
		int t=get();
		r=t==0?r+1:0;
	}
	r=0;
/*
	for(i=0;i<x;i++)for(ptr=j=0;j<=y;j++){
		//printf("%d %d %d %d\n",i,j,ptr,m[j][i]);
		if(!ptr || st[ptr-1]<m[j][i])st[ptr++]=m[j][i];
		else{
			for(;ptr && st[ptr-1]>m[j][i];){
				int _y=(j-(ptr-1)),_x=st[--ptr];
				//printf("%d %d\n",_x,_y);
				if(r<_x*_y)r=_x*_y;
			}
			st[ptr++]=m[j][i];
		}
	}
*/
	Rectangle rect;
	for(int i=0;i<x;i++){
		stack<Rectangle> stk;
		rect.height = 0;
		rect.pos = 0;
		stk.push(rect);
		int pop=0;
		for(int j=0;j<=y;j++){
			rect.height = m[j][i];
			rect.pos = j;
			if(stk.empty() || stk.top().height < rect.height){
				stk.push(rect);
			}else{
				//printf("[-] %d %d\n",i,j);
				for(;!stk.empty() && stk.top().height >= rect.height;){
					pop++;
					Rectangle pre = stk.top(); stk.pop();
					//pre.pos=stk
					int area = pre.height * (j - pre.pos);
					r = max(r, area);
					//printf("%d %d\n",target,pre.pos);
					rect.pos = pre.pos;
				}
				stk.push(rect);
			}
			if(rect.height==0)pop=0;
		}
	}

	printf("%d\n",r);
	return 0;
}