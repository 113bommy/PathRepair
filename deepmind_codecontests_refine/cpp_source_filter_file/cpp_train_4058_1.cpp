#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

string daylist[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
string timelist[2] = {"Day","Night"};
int s,n,t,p,m;
string weekday,time;

double solve(int sweek,int stime){
	double ans = 1;
	for(int i=0;i<m;i++){
		bool flag = true;
		int tindex=0;
		if(stime >= 6*60 && stime < 18*60){
			tindex = 0;
		}else{
			tindex = 1;
		}
		if(weekday == "All" || daylist[sweek] == weekday){
			if(time == "All" || timelist[tindex] == time){
				;
			}else{
				flag = false;
			}
		}else{
			flag = false;
		}

		stime += s;
		if(stime >= 24*60){
			sweek++;
			if(sweek == 7){
				sweek = 0;
			}
			stime -= 24*60;
		}

		if(stime >= 6*60 && stime < 18*60){
			tindex = 0;
		}else{
			tindex = 1;
		}
		if(weekday == "All" || daylist[sweek] == weekday){
			if(time == "All" || timelist[tindex] == time){
				;
			}else{
				flag = false;
			}
		}else{
			flag = false;
		}


		if(flag){
			for(int j=0;j<n;j++){
				ans *= 1-1.0/p;
			}
		}

		stime += (t-s);
		if(stime >= 24*60){
			sweek++;
			if(sweek == 7){
				sweek = 0;
			}
			stime -= 24*60;
		}
	}
	return 1-(double)ans;
}

int main(){
	while(true){
		cin >> s >> n >> t >> weekday >> time >> p >> m;
		if(s == 0){
			break;
		}

		double ans=0;
		for(int i=0;i<7;i++){
			for(int j=0;j<(24*60);j++){
				ans = max (ans,solve(i,j));
			}	
		}
		printf("%.10f\n",ans);
	}
}