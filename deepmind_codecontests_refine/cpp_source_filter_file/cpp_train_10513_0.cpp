 #include <bits/stdc++.h>
                                        #include<iostream>
                                        #include<cstdio>
                                        #include<vector>
                                        #include<queue>
                                        #include<map>
                                        #include<cstring>
                                        #include<string>
                                        #include <math.h>
                                        #include<algorithm>
                                    //    #include <boost/multiprecision/cpp_int.hpp>
                                        #include<functional>
                               #define int long long
                                        #define inf  1000000007
                                        #define pa pair<int,int>
                                        #define ll long long
                                        #define pal pair<double,pa>
                                        #define ppap pair<pa,int>
                                  
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-10)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
                                        using namespace std;
                               class pas{
                                        	public:
                                        	int x,y,h;
                                        	pas(int x=0,int y=0,int h=0):x(x),y(y),h(h) {}
                                        	bool operator < (const pas &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pas &p) const{
                                        		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                        	}
                                        		
                                        
                                        };
                                        class pa2{
                                        	public:
                                        	int x,y;
                                        	pa2(int x=0,int y=0):x(x),y(y) {}
                                        	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
                                        	bool operator < (const pa2 &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pa2 &p) const{
                                        		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                        	}
                                        		
                                        
                                        };
                                        
                                               #define ppa pair<int,pas>
                                        class Point{
                                        	public:
                                        	double x,y;
                                        	Point(double x=0,double y=0):x(x),y(y) {}
                                        	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
                                        	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
                                        	Point operator * (double a) {return Point(x*a,y*a);}
                                        	Point operator / (double a) {return Point(x/a,y/a);}
                                        	double absv() {return sqrt(norm());}
                                        	double norm() {return x*x+y*y;}
                                        	bool operator < (const Point &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const Point &p) const{
                                        		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
                                        	}
                                        };
                                        typedef Point Vector;
                                 #define pl pair<int,pas>
                                        struct Segment{
                                        Point p1,p2;
                                        };
                                         double dot(Vector a,Vector b){
                                        	return a.x*b.x+a.y*b.y;
                                        }
                                        double cross(Vector a,Vector b){
                                        	return a.x*b.y-a.y*b.x;
                                        }
                                    
            bool parareru(Point a,Point b,Point c,Point d){
            //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;
            	return abs(cross(a-b,d-c))<EPS;
            }
            double distance_ls_p(Point a, Point b, Point c) {
              if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
              if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
              return abs(cross(b-a, c-a)) / (b-a).absv();
            }
            bool is_intersected_ls(Segment a,Segment b) {
            	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;
            	if(parareru((a.p2),(a.p1),(a.p1),(b.p2))&&parareru((a.p2),(a.p1),(a.p1),(b.p1))){
            //		cout<<"sss"<<endl;
            		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
            		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
            		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
            		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
            		return false;
            	}
              else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
            }
             
            double segment_dis(Segment a,Segment b){
            	if(is_intersected_ls(a,b))return 0;
            	double r=distance_ls_p(a.p1, a.p2, b.p1);
            	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));
            	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));
            	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));
            	return r;
            }
            Point intersection_ls(Segment a, Segment b) {
              Point ba = b.p2-b.p1;
              double d1 = abs(cross(ba, a.p1-b.p1));
              double d2 = abs(cross(ba, a.p2-b.p1));
              double t = d1 / (d1 + d2);
             
              return a.p1 + (a.p2-a.p1) * t;
            }
             
                            string itos( int i ) {
                            ostringstream s ;
                            s << i ;
                            return s.str() ;
                            }
                             
                            int gcd(int v,int b){
                            	if(v>b) return gcd(b,v);
                            	if(v==b) return b;
                            	if(b%v==0) return v;
                            	return gcd(v,b%v);
                            }
             
                            double distans(double x1,double y1,double x2,double y2){
                            	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                            	return sqrt(rr);
                            	
                            }
                            
   //         int pr[2000010];
     //       int inv[2000010];
            /*
            int beki(int wa,int rr,int warukazu){
            	if(rr==0) return 1ll;
            	if(rr==1) return wa%warukazu;
            	if(rr%2==1) return (beki(wa,rr-1,warukazu)*wa)%warukazu;
            	int zx=beki(wa,rr/2,warukazu);
            	return (zx*zx)%warukazu;
            }
            
			int comb(int nn,int rr){
				int r=pr[nn]*inv[rr];
				r%=inf;
				r*=inv[nn-rr];
				r%=inf;
				return r;
			}
            
            void gya(int ert){
            	pr[0]=1;
            	for(int i=1;i<ert;i++){
            		pr[i]=(pr[i-1]*i)%inf;
            	}
            	for(int i=0;i<ert;i++) inv[i]=beki(pr[i],inf-2,inf);
            	
            }
             */
            
             //sort(ve.begin(),ve.end(),greater<int>());
                                     //----------------kokomade tenpure------------
            //vector<double> ans(100000000),ans2(100000000);
typedef struct node{
node* left;
	node* right;
	int val;
}node;
 
node* new_node(){
	node *n=new node;
	n->left=NULL;
	n->right =NULL;
	n->val=0;
	return n;
 
}
void make_node(node* v,string s){
//	cout<<s<<endl;
	int l=s.length();
	int it,cn=0;
	for( it=0;it<l;it++){
		if(s[it]=='(')cn++;
		if(s[it]==')')cn--;
		
		if(cn==0 && s[it]=='[') break;
	}
	if(it!=2){
	string s2=s.substr(1,it-2);
		node* h=new_node();
		make_node(h,s2);
	v->left=h;
	//	cout<<s2<<endl;
		
	}
	int r=0;
	it++;
	while(s[it]<='9' && s[it]>='0'){
		r*=10;
		r+= s[it]-'0';
		it++;
	}
	//cout<<r<<endl;
	v->val=r;
	
	string s22=s.substr(it+1);
	//cout<<s22<<endl;
	if(s22.length()>2){
		int l2=s22.length();
		node* hh=new_node();
		make_node(hh,s22.substr(1,l2-2));
		v->right=hh;
		
		
	}
	
}

void cul(node* v3,node* v1,node* v2){
	v3->val=v1->val + v2->val;
	
	if(v1->left !=NULL && v2->left !=NULL ){
		node* vl=new_node();
		cul(vl,v1->left,v2->left);
		v3->left=vl;
	}
	if(v1->right !=NULL && v2->right !=NULL ){
		node* vl=new_node();
		cul(vl,v1->right,v2->right);
		v3->right =vl;
	}
}
saiki(node* v){
	cout<<"(";
		if(v->left!=NULL)saiki(v->left);
		cout<<")[";
	cout<<v->val;
	cout<<"](";
		if(v->right!=NULL)saiki(v->right);
		cout<<")";
}
   signed main(){
   	
   string s1,s2;
   	cin>>s1>>s2;
   	
   	node* v1=new_node();
   	node* v2=new_node();
   	
   	make_node(v1,s1);
   	make_node(v2,s2);
   	
   	node* v3=new_node();
   	cul(v3,v1,v2);
   	saiki(v3);
   	cout<<endl;
   	return 0;
        }
