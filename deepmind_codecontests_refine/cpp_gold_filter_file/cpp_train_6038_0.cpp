#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

 namespace tree {
	void dfs(const int now, const vector<vector<int>>&edges, vector<int>&memo, int depth) {
		memo[now] = depth;
		for (auto e : edges[now]) {
			if (memo[e] == -1) {
				
				dfs(e, edges, memo, depth + 1);
			}
		}
	}

	vector<int> dia(const vector<vector<int>>&edges,const int from) {
		vector<int>memo(edges.size(), -1);
		{
			memo[from] = 0;
			dfs(from, edges, memo, 0);
		}
		auto it = max_element(memo.begin(), memo.end());
		{
			int start = it - memo.begin();
			vector<int>nmemo(edges.size(), -1); 
			nmemo[start] = 0;
			dfs(start, edges, nmemo, 0);

			int k=max_element(nmemo.begin(),nmemo.end())-nmemo.begin();

			vector<int>v{ k };
			for(int de=nmemo[k];de>=1;--de){
				for (auto e : edges[k]) {
					if (nmemo[e] == de - 1) {
						v.push_back(e);
						k=e;
						break;
					}
				}
			}
			return v;
		}
	}

	using Hash = pair<long long int, long long int>;

	vector<Hash>ps;
	Hash mk_hash(const vector<vector<int>>&tree, const int now, const int from,const int depth) {
		static bool flag=false;
		static vector<Hash>ps;
		if (!flag) {
			flag=true;
			ps.resize(400000);
			for (int i = 0; i < 400000; ++i) {
				ps[i]=make_pair(rand(),rand());
			}
		}
		Hash ha(1,1);
		for (auto e : tree[now]) {
			if(e==from)continue;
			else {
				auto n_ha(mk_hash(tree,e,now,depth+1));
				ha.first*=(n_ha.first+ps[depth].first);
				ha.second*=(n_ha.second+ps[depth].second);

				ha.first%= 1000000007;
				ha.second%=1000000009;
			}
		}

		return ha;
	}


	Hash rooted_tree_hash(const vector<vector<int>>&tree, const int root) {
		return mk_hash(tree,root,-1,0);
	}

	void adfs(const vector<vector<int>>&forest, const int now, const int from, int &id, vector<vector<int>>&tree,vector<int>&used) {
		used[now]=true;
		const int myid=id;
		for (auto e : forest[now]) {
			if (e != from) {
				id++;
				tree[myid].push_back(id);
				tree.push_back(vector<int>());
				tree[id].push_back(myid);
				adfs(forest,e,now,id,tree,used);
			}
		}
	}

	vector<vector<vector<int>>>to_tree(const vector<vector<int>>&forest) {
		vector<int>used(forest.size());

		vector<vector<vector<int>>>trees;

		for (int i = 0; i < forest.size(); ++i) {
			if (!used[i]) {
				vector<vector<int>>tree(1);
				int id=0;
				adfs(forest,i,-1,id,tree,used);
				trees.push_back(tree);
			}
		}
		return trees;
	}
};

 vector<tree::Hash>get_ha(const vector<vector<int>>&edges) {
	 vector<int>adia = tree::dia(edges, 0);

	 vector<tree::Hash>hashes;
	 if (adia.size() % 2) {
		 tree::Hash ha = tree::rooted_tree_hash(edges, adia[adia.size() / 2]);
		 hashes.push_back(ha);
	 }
	 else {
		 tree::Hash ha1 = tree::rooted_tree_hash(edges, adia[adia.size() / 2 - 1]);
		 tree::Hash ha2 = tree::rooted_tree_hash(edges, adia[adia.size() / 2]);
		 hashes = vector<tree::Hash>{ ha1,ha2 };
	 }
	 return hashes;
 }

int main()
{
	int N,M;cin>>N>>M;
	vector<vector<int>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a,b;cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<vector<vector<int>>>trees=tree::to_tree(edges);


	int N2;cin>>N2;
	vector<vector<int>>tree2(N2);
	for (int i = 0; i < N2 - 1; ++i) {
		int a,b;cin>>a>>b;
		tree2[a-1].push_back(b-1);
		tree2[b-1].push_back(a-1);
	}

	int ans=0;

	auto hashes2=get_ha(tree2);
	for (int i = 0; i < trees.size(); ++i) {
		//if(trees[i].size()!=N2)continue;
		auto hashes1=get_ha(trees[i]);
		int nans=0;
		for (auto ha1 : hashes1) {
			for (auto ha2 : hashes2) {
				if (ha1 == ha2) {
					nans=1;
				}
			}
		}
		ans+=nans;
		
	}
	cout<<ans<<endl;
	return 0;
}
