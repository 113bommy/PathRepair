#include <bits/stdc++.h>
using namespace std;

struct st{
	st *linkk[27];
	st *up;
	int cnt;
	int belong;
	int att;
	int val;
	int en;
	st(){
		for (int i = 0; i < 27; i++){
			linkk[i] = NULL;
		}
		cnt = 0;
		en = 0;
	}
};


int n;
int q;

#define MAX 400002

char buf[MAX];

vector<string> v;




st linkk2[MAX * 30];
int ord = 0;
st *neww(){
	ord++;
	return &linkk2[ord - 1];
}


st *root;
vector<st*> lis;

void ins(string &a){
	st *b = root;
	for (int i = 0; i < a.size(); i++){
		if (b->linkk[a[i] - 'a'] == NULL){
			b->linkk[a[i] - 'a'] = neww();
			b->linkk[a[i] - 'a']->up = b;
		}
		b = b->linkk[a[i] - 'a'];
	}
	b->en++;
	lis.push_back(b);
}

inline void dfs(st *b){
	bool f = false;
	b->cnt = b->en;
	for (int i = 0; i < 26; i++){
		if (b->linkk[i] != NULL){
			f = true;
			b->linkk[i]->val = i;
			dfs(b->linkk[i]);
			b->cnt += b->linkk[i]->cnt;
		}
	}
}

map < st*, vector<pair<string, int> > > mp;

int store[27][27];
int outt[MAX];
int F = 0;
inline void dfs2(st *b){
	F += b->en;
	for (int i = 0; i < 26; i++){
		if (b->linkk[i] != NULL){
			for (int j = 0; j < 26; j++){
				if (i != j){
					if (b->linkk[j] != NULL){
						store[i][j] += b->linkk[j]->cnt;
					}
				}
			}
			dfs2(b->linkk[i]);
			for (int j = 0; j < 26; j++){
				if (i != j){
					if (b->linkk[j] != NULL){
						store[i][j] -= b->linkk[j]->cnt;
					}
				}
			}
		}
	}
	F-=b->en;
	if (mp.count(b)){
		vector<pair<string, int> > &V = mp[b];
		for (int i = 0; i < V.size(); i++){
			int ans = 0;
			for (int j = 0; j < 26; j++){
				for (int k = 0; k < j; k++){
					ans += store[V[i].first[j]-'a'][V[i].first[k]-'a'];
				}
			}
			outt[V[i].second] = ans+F;
		}
	}
}

int main(){
	root = neww();
	root->up = NULL;
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%s", buf);
		v.push_back(buf);
		ins(v.back());
	}
	dfs(root);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int id;
		scanf("%d", &id);
		id--;
		scanf("%s", buf);
		mp[lis[id]].push_back(make_pair(buf,i) );
	}
	dfs2(root);
	for (int i = 0; i < q; i++){
		printf("%d\n", outt[i] + 1);
	}
	return 0;
}
