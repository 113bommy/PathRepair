// 2009ツアツジツアツ地ツ凝ヲツ予ツ選 G : Malfatti Circles
#include <fstream>
#include <complex>
#include <stdio.h>

using namespace std;

const double EPS = 1e-12;

typedef complex<double> P;
struct L{ P p, q; L(P p, P q) : p(p), q(q) {} };

double cross(P a, P b) { return imag(conj(a)*b); }

double lpDist(L l, P p){
	return abs(cross(l.q-l.p,p-l.p))/abs(l.q-l.p);
}

P crossPoint(L l, L m){
	double A = cross(l.q-l.p, m.q-m.p);
	double B = cross(l.q-l.p, l.q-m.p);
	return m.p + B/A*(m.q-m.p);
}

int main(){
	int x1, y1, x2, y2, x3, y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		if(!(x1||y1||x2||y2||x3||y3)) break;
		P p1 = P(x1,y1), p2 = P(x2,y2), p3 = P(x3,y3);
		P dirA = (p2-p1)/abs(p2-p1)+(p3-p1)/abs(p3-p1);
		P dirB = (p1-p2)/abs(p1-p2)+(p3-p2)/abs(p3-p2);
		P c = crossPoint(L(p1,p1+dirA),L(p2,p2+dirB));
		double rA, rB, rC;
		double leftA = 0.0, rightA = 1.0, leftB, rightB, leftC, rightC;
		while(true){
			double midA = (leftA+rightA)/2;
			P cA = p1 + (c-p1)*midA, cB, cC;
			rA = lpDist(L(p1,p2), cA);
			leftB = 0.0, rightB = 1.0, leftC = 0.0, rightC = 1.0;
			while(rightB-leftB>EPS){
				double midB = (leftB+rightB)/2;
				cB = p2 + (c-p2)*midB;
				rB = lpDist(L(p2,p3), cB);
				if(rA+rB < abs(cB-cA)) leftB  = midB;
				else                   rightB = midB;
			}
			while(rightC-leftC>EPS){
				double midC = (leftC+rightC)/2;
				cC = p3 + (c-p3)*midC;
				rC = lpDist(L(p3,p1), cC);
				if(rA+rC < abs(cC-cA)) leftC  = midC;
				else                   rightC = midC;
			}
			if(rB+rC > abs(cB-cC)) leftA  = midA;
			else                   rightA = midA;
			if(rightA-leftA < EPS){
				printf("%.5lf %.5lf %.5lf\n", rA, rB, rC);
				break;
			}
		}
	}
}