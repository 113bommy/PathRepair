#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
FILE *fin, *fout;
int N, M;
vector<vector<int> > adj;
vector<vector<int> > dist;
void get_dist() {
  dist = vector<vector<int> >(N, vector<int>(N, inf));
  for (int i = 0; i < N; i++) {
    dist[i][i] = 0;
    for (int j = 0; j < adj[i].size(); j++) {
      dist[i][adj[i][j]] = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
}
vector<vector<int> > dist_cnt;
void get_dist_cnt() {
  dist_cnt = vector<vector<int> >(N, vector<int>(N + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist_cnt[i][dist[i][j]]++;
    }
  }
}
vector<int> interesting;
vector<double> prob_interesting, dist_prob;
void solve() {
  double maxi = 0;
  dist_prob = vector<double>(N + 1, 0);
  for (int g1 = 0; g1 < N; g1++) {
    double prob = 0;
    for (int d1 = 0; d1 <= N; d1++) {
      if (dist_cnt[g1][d1] == 0) continue;
      if (dist_cnt[g1][d1] == 1) {
        prob += (double)dist_cnt[g1][d1] / N;
        continue;
      }
      interesting.clear();
      for (int i = 0; i < N; i++) {
        if (dist[g1][i] == d1) {
          for (int j = 0; j < adj[i].size(); j++) {
            int k = adj[i][j];
            interesting.push_back(k);
          }
        }
      }
      sort((interesting).begin(), (interesting).end());
      interesting.resize(unique((interesting).begin(), (interesting).end()) -
                         interesting.begin());
      prob_interesting.clear(),
          prob_interesting = vector<double>(interesting.size(), 0);
      for (int i = 0; i < interesting.size(); i++) {
        int o = interesting[i];
        for (int j = 0; j < adj[o].size(); j++) {
          int oo = adj[o][j];
          if (dist[g1][oo] == d1)
            prob_interesting[i] +=
                (double)1 / adj[oo].size() * (double)1 / dist_cnt[g1][d1];
        }
      }
      double maxi2 = 0;
      for (int g2 = 0; g2 < N; g2++) {
        double prob2 = 0;
        for (int i = 0; i < interesting.size(); i++) {
          dist_prob[dist[g2][interesting[i]]] =
              max(dist_prob[dist[g2][interesting[i]]], prob_interesting[i]);
        }
        for (int i = 0; i < interesting.size(); i++) {
          prob2 += dist_prob[dist[g2][interesting[i]]];
          dist_prob[dist[g2][interesting[i]]] = 0;
        }
        maxi2 = max(maxi2, prob2);
      }
      maxi2 = max(maxi2, (double)1 / dist_cnt[g1][d1]);
      prob += (double)dist_cnt[g1][d1] / N * maxi2;
    }
    maxi = max(maxi, prob);
  }
  printf("%.20lf", maxi);
}
int main() {
  scanf("%d %d", &N, &M);
  adj.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  get_dist();
  get_dist_cnt();
  solve();
}
