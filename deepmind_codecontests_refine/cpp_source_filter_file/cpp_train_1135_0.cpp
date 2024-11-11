#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
#define REP(i,a,b)for(int i=a;i<b;i++)

struct POINT{
	int x;
	int y;
	int c;
	POINT(){};
	POINT(int X,int Y,int C){
		x=X;y=Y;c=C;
	}
};

struct BLOCK{
	POINT pt[4];
	bool flag;
};

struct INFO{
	int count;
	double gp;
	INFO(int c,double g){
		count=c; gp=g;
	}
};

BLOCK bl[160];
stack<POINT> st;
int ary[60][10][2]={0};
int h,w;
char tmp;
double sum=0;
int dep_c=1;


double g_point(int k){
		int wei[4]={0};
		int wei_p=0;
		int x=-100;
		double t_sum=0.0;
		REP(i,0,w){
			REP(j,0,h){
				if(ary[j][i][1]==k){
					if(x<0)x=i;
					wei[wei_p]++;
				}
			}
			if(wei[wei_p])wei_p++;
			if(wei_p==4)break;
		}
		if(wei[0]==4){
			t_sum=(0.5+x);
		}else if(wei[0]==3){
			t_sum=(0.75+x);
		}else if(wei[0]==2){
			if(wei[1]==1) t_sum=(1.25+x);
			else t_sum=(1+x);
		}else if(wei[0]==1){
			if(wei[1]==1){
				if(wei[2]==1) t_sum=(2+x);
				else t_sum=(1.75+x);
			}else if(wei[1]==2){
				t_sum=(1.5+x);
			}else{
				t_sum=(1.25+x);
			}
		}
		return t_sum;
}

void depth(POINT pt,int it){
	ary[pt.y][pt.x][1]=dep_c;
	bl[dep_c].pt[it].x=pt.x;
	bl[dep_c].pt[it].y=pt.y;
	if(pt.y>0&&ary[pt.y-1][pt.x][0]==pt.c&&!ary[pt.y-1][pt.x][1])
		st.push(POINT(pt.x,pt.y-1,pt.c));
	if(pt.y<59&&ary[pt.y+1][pt.x][0]==pt.c&&!ary[pt.y+1][pt.x][1])
		st.push(POINT(pt.x,pt.y+1,pt.c));
	if(pt.x>0&&ary[pt.y][pt.x-1][0]==pt.c&&!ary[pt.y][pt.x-1][1])
		st.push(POINT(pt.x-1,pt.y,pt.c));
	if(pt.x<9&&ary[pt.y][pt.x+1][0]==pt.c&&!ary[pt.y][pt.x+1][1])
		st.push(POINT(pt.x+1,pt.y,pt.c));
	while(1){
		if(!st.empty()){
			POINT t_pt=st.top();
			st.pop();
			if(!ary[t_pt.y][t_pt.x][1])
				depth(t_pt,it+1);
		}else
			break;
	}
}

INFO check(int k,int bk){
	bl[k].flag=1;
	INFO info(1,g_point(k));
	REP(i,0,4){
		if(bl[k].pt[i].y>0 
			&& ary[bl[k].pt[i].y-1][bl[k].pt[i].x][1] != k
			&& ary[bl[k].pt[i].y-1][bl[k].pt[i].x][1]
			&& !bl[ary[bl[k].pt[i].y-1][bl[k].pt[i].x][1]].flag){
				INFO t_info = check(ary[bl[k].pt[i].y-1][bl[k].pt[i].x][1],k);
				if(!t_info.count) return t_info;
				info.gp = (info.gp*info.count+t_info.gp*t_info.count)/(info.count+t_info.count);
				info.count += t_info.count;
		}
	}
	int left=100,right=-1;
	REP(i,0,4){
		if(bk==0){
			if(bl[k].pt[i].y==h-1){
				if( bl[k].pt[i].x < left) left=bl[k].pt[i].x;
				if( bl[k].pt[i].x +1 > right) right=bl[k].pt[i].x+1;
			}
		}else{
			if(ary[bl[k].pt[i].y+1][bl[k].pt[i].x][1]==bk){
				if( bl[k].pt[i].x < left) left=bl[k].pt[i].x;
				if( bl[k].pt[i].x +1 > right) right=bl[k].pt[i].x+1;
			}
		}
	}
	if(left<info.gp&&info.gp<right)	return info;
	else return INFO(0,0);
}



int main(void){

	while(1){

	cin>>w>>h;

	if(!w&&!h)break;

	REP(i,0,60)REP(j,0,10)REP(k,0,2)ary[i][j][k]=0;
	sum=0;
	dep_c=1;

	REP(i,0,h){
		REP(j,0,w){
			cin >> tmp;
			if(tmp=='.')ary[i][j][0]=0;
			else ary[i][j][0]=(tmp-'0');
		}
	}

	REP(i,0,h){
		REP(j,0,w){
			if(ary[i][j][0]&&!ary[i][j][1]){
				bl[dep_c].flag=0;
				depth(POINT(j,i,ary[i][j][0]),0);
				dep_c++;
			}
		}
	}


	REP(i,0,w)
		if(ary[h-1][i][1]){
			INFO info = check(ary[h-1][i][1],0);
			if(info.count) cout<<"STABLE"<<endl;
			else cout<<"UNSTABLE"<<endl;
			break;
		}


	return 0;
}