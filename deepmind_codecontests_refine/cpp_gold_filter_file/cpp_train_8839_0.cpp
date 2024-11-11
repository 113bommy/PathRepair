#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef pair<P,P> Edge;

typedef long long ll;

const double PI=4*atan(1.0);
const int MAX_SIZE = 10000;

// àÏ
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
// OÏ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// _cª¼üabãÉ é©È¢©
int is_point_on_line(P a, P b, P c) {
  return EQ( cross(b-a, c-a), 0.0 );
}
// 2¼üÌ¼s»è
int is_orthogonal(P a1, P a2, P b1, P b2) {
  return EQ( dot(a1-a2, b1-b2), 0.0 );
}
// 2¼üÌ½s»è
int is_parallel(P a1, P a2, P b1, P b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}
// _a,bðÊé¼üÆ_cÌÔÌ£
double distance_l_p(P a, P b, P c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}
// _a,bð[_Æ·éüªÆ_cÆÌ£
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð·»è
int is_intersected_ls(P a1, P a2, P b1, P b2) {
    // üªª½sÈêÍdÈÁÄ¢é±ÆÉ·é
    if(abs(cross(a2-a1,b2-b1)) < EPS){
        return 1;
    }
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð_vZ
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}
// a1,a2ðÊé¼üÆb1,b2ðÊé¼üÌð·»è
int is_intersected_l(P a1, P a2, P b1, P b2) {
  return !EQ( cross(a1-a2, b1-b2), 0.0 );
}
// a1,a2ðÊé¼üÆb1,b2ðÊé¼üÌð_vZ
P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1; P b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}
/*
~üÆüªÌð·»è
*/
bool isCircleCrossLine(P a,P b,P c,double r){
	double d1 = abs(a-c);
	double d2 = abs(b-c);
    // üªªÉÜÜêéÆ«A±±ÌRgAEgðÍ¸¹Îtrue(ð·)ÆÈé
	//if(d1<r&&d2<r)
	//	return true;
	double d = distance_ls_p(a,b,c);
	return (EQ(d,r)||d<r);
}
// Op`ÌàÉ_ª é©Ç¤©
// OÏÌ³ª·×Ä¯¶ÈçàÉ_ è
bool isInTriangle(P p1,P p2,P p3,P s){
	P a=p1-s;
	P b=p2-s;
	P c=p3-s;
	return ((cross(a,b)>0&&cross(b,c)>0&&cross(c,a)>0)||(cross(a,b)<0&&cross(b,c)<0&&cross(c,a)<0));
}
// é`ÌÉ_ª¶Ý·é©Ç¤©
bool isInRectangle(P p1,P p2,P p3,P p4,P s){
	P a=p1-s;
	P b=p2-s;
	P c=p3-s;
    P d=p4-s;
	return ((cross(a,b)>0&&cross(b,c)>0&&cross(c,d)>0&&cross(d,a)>0)
        ||(cross(a,b)<0&&cross(b,c)<0&&cross(c,d)<0&&cross(d,a)<0));
}
// Op`ÌÊÏðÀW©çvZ
double calcAreaOfTriangle(P a,P b,P c){
	return abs((b.real()-a.real())*(c.imag()-a.imag()) - (c.real()-a.real())*(b.imag()-a.imag()))/2;
}
// ^¦çê½~ÌÍÍàÉ_ª¶Ý·é©Ç¤©
bool isContainingDot(P c,double r,P a){
	return (((c.real()-a.real())*(c.real()-a.real())
		+(c.imag()-a.imag())*(c.imag()-a.imag())<r*r)
		||EQ((c.real()-a.real())*(c.real()-a.real())
		+(c.imag()-a.imag())*(c.imag()-a.imag()),r*r));
}
// ½p`ÌÊÏö®
double calcPolygonArea(vector<P> p){
	double sum=0;
	for(int i = 0; i < p.size(); i++)
		sum+=cross(p[i],p[(i+1)%(p.size())]);
	return sum/2;
}
// 2xNgÔÌpx
// a©çbÖ¶üèÅ½x©(0->2*PI)
double diffAngle(P a,P b){
    double angle=atan2(cross(a,b),dot(a,b));
    if(angle<0)
        return 2*PI+angle;
    return angle;
}

// 2ÂÌxNgÌdÈÁÄ¢éªÌ·³ðÔ·
// àµdÈÁÄ¢È¯êÎ0ðÔ·
double multipleLength(P a,P b,P c,P d){
    Edge e1=make_pair(a,b);
    Edge e2=make_pair(c,d);
    // ½sÅ é©Ç¤©
    if(!(is_parallel(e1.first,e2.first,e1.second,e2.second)
        &&is_parallel(e1.first,e1.second,e2.first,e2.second)))
        return 0;
    double dist=0;
    // ¼ûæÁÄ¢é
    if(EQ(distance_ls_p(e1.first,e1.second,e2.first),0)&&EQ(distance_ls_p(e1.first,e1.second,e2.second),0))
        dist=abs(e2.first-e2.second);
    else if(EQ(distance_ls_p(e2.first,e2.second,e1.first),0)&&EQ(distance_ls_p(e2.first,e2.second,e1.second),0))
        dist=abs(e1.first-e1.second);
    else if(EQ(distance_ls_p(e1.first,e1.second,e2.first),0)){
        // Ç¿çªüãÉ é©
        if(EQ(distance_ls_p(e2.first,e2.second,e1.first),0))
            dist=abs(e1.first-e2.first);
        else
            dist=abs(e1.second-e2.first);
    }
    else if(EQ(distance_ls_p(e1.first,e1.second,e2.second),0)){
        if(EQ(distance_ls_p(e2.first,e2.second,e1.first),0))
            dist=abs(e1.first-e2.second);
        else
            dist=abs(e1.second-e2.second);
    }
    return dist;
}

struct Polygon{
    vector<Edge> edges;
};

int n;
int idx;
vector<Polygon> polygons;
map<string,int> nti;
vector<int> G[10001];
string nodeStr[10001];
int minColor=10000;
bool passed[10001];

//// ·×ÄÌm[hªðð½µÄ¢é©ðmF·é
//void dfs(int s,string &str){
//}

void dfs(int rem,string s,char num){
    if(rem==0){
        // ®¬µ½¶ñÌhèûÅÊêé©·B
        // ÊêéêÍAÅ¬hèðXVÅ«éÌÅ êÎAXV·é
        bool ok=true;
        memset(passed,0,sizeof(passed));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < G[i].size(); j++){
                // ¯¶m[h©AÊÌF
                if(!(nodeStr[G[i][j]]==nodeStr[i]||s[nti[nodeStr[i]]]!=s[nti[nodeStr[G[i][j]]]])){
                    ok=false;
                    break;
                }
            }
            if(!ok)break;
        }
        if(ok)
            minColor=min(minColor,num-'0');
    }
    else{
        for(char ch='0'; ch<=num; ch++){
            if(ch==num)
                dfs(rem-1,s+ch,num+1);
            else
                dfs(rem-1,s+ch,num);
        }
    }
}

int main(){

    while(cin>>n&&n!=0){
        minColor=10000;
        for(int i = 0; i < n; i++)G[i].clear();
        idx=0;
        nti.clear();
        polygons.clear();
        for(int i = 0; i < n; i++){
            Polygon pol;
            string name;
            cin>>name;
            // idxðo^
            if(nti.find(name)==nti.end())
                nti[name]=idx++;
            // ¼Oðo^
            nodeStr[i]=name;
            int x,y;
            int px,py;
            int sx,sy;
            cin>>px>>py;
            sx=px;sy=py;
            while(cin>>x&&x!=-1){
                cin>>y;
                pol.edges.push_back(make_pair(P(px,py),P(x,y)));
                px=x;
                py=y;
            }
            // ÅãÌC
            pol.edges.push_back(make_pair(P(px,py),P(sx,sy)));
            polygons.push_back(pol);
        }
        // ×Úð`FbN
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                bool isAdj=false;
                // »ê¼êÌÓª×ÚµÄ¢é©`FbN
                for(int k = 0; k < polygons[i].edges.size(); k++){
                    for(int l = 0; l < polygons[j].edges.size(); l++){
                        Edge &e1=polygons[i].edges[k];
                        Edge &e2=polygons[j].edges[l];
                        double dist=multipleLength(e1.first,e1.second,e2.first,e2.second);
                        //// ½sÅ é©Ç¤©
                        //if(!(is_parallel(e1.first,e2.first,e1.second,e2.second)
                        //    &&is_parallel(e1.first,e1.second,e2.first,e2.second)))
                        //    continue;
                        //double dist=0;
                        //// ¼ûæÁÄ¢é
                        //if(EQ(distance_ls_p(e1.first,e1.second,e2.first),0)&&EQ(distance_ls_p(e1.first,e1.second,e2.second),0)){
                        //    dist=abs(e2.first-e2.second);
                        //}
                        //else if(EQ(distance_ls_p(e2.first,e2.second,e1.first),0)&&EQ(distance_ls_p(e2.first,e2.second,e1.second),0)){
                        //    dist=abs(e1.first-e1.second);
                        //}
                        //else if(EQ(distance_ls_p(e1.first,e1.second,e2.first),0)){
                        //    // Ç¿çªüãÉ é©
                        //    if(EQ(distance_ls_p(e2.first,e2.second,e1.first),0))
                        //        dist=abs(e1.first-e2.first);
                        //    else
                        //        dist=abs(e1.second-e2.first);
                        //}
                        //else if(EQ(distance_ls_p(e1.first,e1.second,e2.second),0)){
                        //    if(EQ(distance_ls_p(e2.first,e2.second,e1.first),0))
                        //        dist=abs(e1.first-e2.second);
                        //    else
                        //        dist=abs(e1.second-e2.second);
                        //}
                        //else
                        //    continue;
                        if(!EQ(dist,0)){
                            // ×ÚµÄ¢éÈçÎAedgeðø­
                            isAdj=true;
                            break;
                        }
                    }
                    if(isAdj)break;
                }
                // draw edge
                if(isAdj){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        dfs(nti.size(),"",'0');
        cout<<minColor<<endl;
    }

    return 0;
}