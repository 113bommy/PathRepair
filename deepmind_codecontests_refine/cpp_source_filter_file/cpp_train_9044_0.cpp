#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define REP(i, n) FOR(i, 0, n)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
#define PB push_back
#define MP make_pair

ld dst(ld x1, ld y1, ld x2, ld y2){
	x1-=x2;
	y1-=y2;
	return sqrt(x1*x1+y1*y1);
}
int sgn(ld a){
	if(a>0) return 1;
	else if(a<0) return -1;
	else return 0;
}
int linsgn(ld a, ld b, ld c, ld d, ld x, ld y){
	return sgn((d-b)*x-(c-a)*y-a*d+b*c);
}
bool cross(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x4, ld y4){
	return linsgn(x1,y1,x2,y2,x3,y3)*linsgn(x1,y1,x2,y2,x4,y4)<=0 &&
		linsgn(x3,y3,x4,y4,x1,y1)*linsgn(x3,y3,x4,y4,x2,y2)<=0;
}
void tim(ld &a, ld &b, ld c, ld d){
	ld e=a, f=b;
	a=c*e-d*f;
	b=c*f+d*e;
}
void flp(ld &p, ld &q, ld a, ld b, ld x, ld y){
	p-=a; x-=a;
	q-=b; y-=b;
	ld r=dst(0,0,x,y);
	tim(x, y, x, y);
	q*=-1;
	tim(p, q, x, y);
	p/=r*r; q/=r*r;
	p+=a;
	q+=b;
}
void cpt(ld &p, ld &q, ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x4, ld y4){
	ld a=y2-y1, b=x2-x1, c=x1*y2-x2*y1, d=y4-y3, e=x4-x3, f=x3*y4-x4*y3;
	p=(b*f-c*e)/(b*d-a*e);
	q=-(a*f-c*d)/(a*e-b*d);
}

struct edge{
	int to; ld cost;
};

#define N 240
int n;
ld x[N], y[N];
ld s[N], t[N];

vector<edge> e[N];
void add_edge(int p, int q, ld a, ld b, ld c, ld d){
	// printf("%d->%d: (%Lf, %Lf)-(%Lf, %Lf)\n", p, q, a, b, c, d);
	ld f=dst(a,b,c,d);
	e[p].PB(edge{q, f});
	e[q].PB(edge{p, f});
}

typedef pair<ld, int> pld;
bool used[N];
priority_queue<pld, vector<pld>, greater<pld>> que;
ld cst[N];

int main(){
	REP(i, 2) scanf("%Lf%Lf", s+i, t+i);
	scanf("%d", &n);
	REP(i, n) scanf("%Lf%Lf", x+i, y+i);
	REP(i, n){
		add_edge(i, (i+1)%n, x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
	}
	REP(i, n){
		REP(j, 2){
			FOR(k, i+1, i+n-1){
				if(cross(s[j],t[j],x[i],y[i],x[k%n],y[k%n],x[(k+1)%n],y[(k+1)%n]))
					goto nxt;
			}
			add_edge(n+j, i, s[j],t[j],x[i],y[i]);
			nxt:;
		}
	}
	REP(i, n){
		// printf("i=%d\n", i);
		ld p=s[1], q=t[1];
		flp(p, q, x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
		// printf("(%Lf, %Lf)\n", p, q);
		if(!cross(s[0],t[0],p,q,x[i], y[i], x[(i+1)%n], y[(i+1)%n])) continue;
		ld u, v;
		cpt(u, v, s[0], t[0], p, q, x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
		REP(j, 2){
			FOR(k, i+1, i+n-1){
				if(cross(s[j],t[j],u,v,x[k%n],y[k%n],x[(k+1)%n],y[(k+1)%n]))
					goto fal;
			}
		}
		REP(j, 2) add_edge(n+j, n+2+i, s[j], t[j], u, v);
fal:;
	}
	fill(cst, cst+N, 1e18);
	fill(used, used+N, false);
	cst[n]=0;
	que.push(MP(0, n));
	while(!used[n+1]){
		pld tp=que.top(); que.pop();
		int nw=tp.second;
		if(used[nw]) continue;
		used[nw]=true;
		REP(i, e[nw]){
			edge &ed=e[nw][i];
			ld ncst=cst[nw]+ed.cost;
			int dst=ed.to;
			if(cst[dst]>ncst){
				cst[dst]=ncst;
				que.push(MP(ncst, dst));
			}
		}
	}
	printf("%Lf\n", cst[n+1]);
}