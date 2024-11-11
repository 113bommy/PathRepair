#include <cstdio>
#include <vector>
using namespace std;

//ax + b = 0
pair<int,int> solve(int a, int b){
	if(b==0) return make_pair(0,0);
	if(b>0) return make_pair(0,1);
	return make_pair(1,0);
}

//ax^2+bx+c=0
pair<int,int> solve(int a, int b, int c){
	if(c==0) return solve(a,b);
	int y4a = -b*b + 4*a*c;
	if(y4a > 0){
		return make_pair(0,0);
	}
	if(c < 0){
		return make_pair(1,1);
	}
	if(b > 0){
		return make_pair(0, 2);
	}
	return make_pair(2, 0);
}

//ax^3+bx^2+cx+d=0
pair<int,int> solve(long long a, long long b, long long c, long  long d){
	if(a < 0){
		return solve(-a,-b,-c,-d);
	}
	if(d == 0){
		return solve(a,b,c);
	}

	long long D = b*b*c*c - 4*a*c*c*c - 4*b*b*b*d - 27*a*a*d*d + 18*a*b*c*d;
	int DD = b*b - 3*a*c;
	bool minimal_x_plus = (b<0 || DD > sq(b)),
			maximal_x_minus = (b>0 || sq(b) < DD);
	if(D >= 0){
		if(DD == 0){
			if(b > 0){
				return make_pair(0,3);
			}
			else{
				return make_pair(3,0);
			}
		}
		if(d > 0){
			if(!minimal_x_plus){
				return make_pair(0,3);
			}
			else{
				return make_pair(2,1);
			}
		}
		else{
			if(!maximal_x_minus){
				return  make_pair(3,0);
			}
			else{
				return make_pair(1,2);
			}
		}
	}
	else{
		if(d > 0){
			return make_pair(0,1);
		}
		return make_pair(1,0);
	}

	return make_pair(-1,-1);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a, b, c, d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		pair<int,int> ans = solve(a,b,c,d);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}