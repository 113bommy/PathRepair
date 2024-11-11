#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
typedef int val_t;
const int memory_limit = 8000000;
struct RBST{
	struct Node{
		Node *lp,*rp;
		int size;
		val_t val;
		val_t mini;
		Node(){}
		Node(val_t v):val(v),mini(v),size(1),lp(NULL),rp(NULL){}
		Node(Node* x):val(x->val),mini(x->mini),size(x->size),lp(x->lp),rp(x->rp){}
	};
	Node *root;
	RBST():root(NULL),memory_size(0){}
	Node pool[memory_limit+10000];
	int memory_size;
	val_t str[400100];
	int length_limit;
	int id;
	int size(Node *x){return !x?0:x->size;}
	val_t min_(Node *x){return !x?INF:x->mini;}
	Node* update(Node *x){
		if(x==NULL)return x;
		x->size = 1+size(x->lp)+size(x->rp);
		x->mini = min(x->val,min(min_(x->lp),min_(x->rp)));
		return x;
	}
	Node* alloc(val_t val){
		return &(pool[memory_size++]=Node(val));
	}
	Node* copy(Node* x){
		return &(pool[memory_size++]=Node(x));
	}
	Node* merge(Node* x,Node* y){
		if(x==NULL)return y;
		if(y==NULL)return x;
		int m = x->size , n = y->size;
		if(rand()%(m+n)<m){
			x = copy(x);
			x->rp = merge(x->rp,y);
			return update(x);
		}else{
			y = copy(y);
			y->lp = merge(x,y->lp);
			return update(y);
		}
	}
	Node* merge_(Node* x,Node* y){
		if(x==NULL)return y;
		if(y==NULL)return x;
		int m = x->size , n = y->size;
		if(rand()%(m+n)<m){
			x->rp = merge(x->rp,y);
			return update(x);
		}else{
			y->lp = merge(x,y->lp);
			return update(y);
		}
	}
	typedef pair<Node*,Node*> Np;
	Np split(Node *x,int k){ //[0,k),[k,n)
		if(x==NULL)return Np(NULL,NULL);
		//assert(k<=(x->size));
		x = copy(x);
		if(k<=size(x->lp)){
			Np s = split(x->lp,k);
			x->lp = s.sec;
			return mp(s.fi,update(x));
		}else{
			Np s = split(x->rp,k-size(x->lp)-1);
			x->rp = s.fi;
			return mp(update(x),s.sec);
		}
	}
	void insert(int k,val_t val){ // 0-indexed
		Np s = split(root,k);
		root = merge(merge(s.fi,alloc(val)),s.sec);
		return;
	}
	val_t erase(int k){ // 0-indexed
		Np s = split(root,k);
		Np s2 = split(s.sec,1);
		root = merge(s.fi,s2.sec);
		return s2.fi->val;
	}
	val_t query(int l,int r){//[l,r)
		Np s = split(root,l);
		Np s2 = split(s.sec,r-l);
		val_t ret = min_(s2.fi);
		root = merge(merge(s.fi,s2.fi),s2.sec);
		return ret;
	}
	void copypaste(int a,int b,int c){ // 0-indexed [a,b) 
		Np s = split(root,a);
		Np s2 = split(s.sec,b-a);
		Np s3 = split(root,c);
		root = merge(merge(s3.fi,s2.fi),s3.sec);
		if(size(root)>length_limit)root = split(root,length_limit).fi;
		return;
	}
	void copy_query1(int sz){
		Np s = split(root,sz);
		Np s2 = split(root,sz);
		root = merge(s2.sec,s.sec);
	}
	void copy_query2(int sz){
		Np s = split(root,sz);
		Np s2 = split(root,sz);
		root = merge(s.fi,s2.fi);
	}
	void write(Node *x){
		if(x==NULL)return;
		write(x->lp);
		str[id++]=x->val;
		write(x->rp);
	}
	void output(Node *x){
		if(x==NULL)return;
		printf("[");
		output(x->lp);
		printf("%d",x->val);
		output(x->rp);
		printf("]");
	}
	void build(){
		memory_size=0;
		root=NULL;
		for(int i=0;i<length_limit;i++)root=merge_(root,alloc(str[i]));
	}
	void rebuild(){
		id=0;
		write(root);
		//assert(id==length_limit);
		build();
	}
	void show(){
		str[id]=-1;
		for(int i=0;i<length_limit;i++)printf("%d ",str[i]);
		printf("\n");
	}
}tree;
int main(){
	int N;
	scanf("%d",&N);
	tree.length_limit = 2*N;
	for(int i=0;i<N;i++)scanf("%d",&tree.str[i]);
	for(int i=0;i<N;i++)scanf("%d",&tree.str[i+N]);
	tree.build();
	/*for(int i=0;i<2*N;i++){
		int a;
		scanf("%d",&a);
		tree.insert(i,a);
		//tree.output(tree.root);
		printf("\n");
	}*/
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int type,y,z;
		scanf("%d",&type);
		scanf("%d %d",&y,&z);
		y--;
		if(type==1){
			tree.erase(y);
			tree.insert(y,z);
			//tree.output(tree.root);
			//printf("\n");
		}else if(type==2){
			tree.erase(y+N);
			tree.insert(y+N,z);
		}else if(type==3){
			printf("%d\n",tree.query(y,z));
		}else if(type==4){
			printf("%d\n",tree.query(y+N,z+N));
		}else if(type==5){
			tree.copy_query1(N);
			//tree.output(tree.root);
		}else{
			tree.copy_query2(N);
			//tree.output(tree.root);
		}
		if(tree.memory_size>memory_limit)tree.rebuild();
	}
	return 0;
}