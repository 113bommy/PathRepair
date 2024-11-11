#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 * 1000 + 50;
const int letter_number = 26;
int n;
bool mark[MAX_N];
vector<int> adj[MAX_N];
vector<int> child[MAX_N];
int dp[MAX_N][2];
struct node {
  node* child[letter_number];
  int number;
  void insert(const string& word, int index) {
    if (index == word.size() - 1) {
      return;
    }
    int current = word[index + 1] - 'a';
    if (child[current] == NULL) {
      child[current] = new node();
      n++;
      child[current]->number = n;
    }
    child[current]->insert(word, index + 1);
  }
  void clear() {
    for (int i = 0; i < letter_number; ++i) {
      if (child[i] != NULL) {
        child[i]->clear();
      }
    }
    delete this;
  }
};
void insert_edge(node* main_word, node* word) {
  if (main_word == NULL || word == NULL) {
    return;
  }
  for (int i = 0; i < letter_number; ++i) {
    if (main_word->child[i] != NULL && word->child[i] != NULL) {
      int u = main_word->child[i]->number;
      int v = word->child[i]->number;
      adj[u].push_back(v);
      adj[v].push_back(u);
      insert_edge(main_word->child[i], word->child[i]);
    }
  }
}
node* root;
void dfs(int u) {
  mark[u] = true;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (!mark[v]) {
      child[u].push_back(v);
      dfs(v);
    }
  }
}
void solve(int u) {
  dp[u][1]++;
  for (int i = 0; i < child[u].size(); ++i) {
    int v = child[u][i];
    solve(v);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}
void clear() {
  if (n <= 0) {
    return;
  }
  for (int i = 0; i <= n; ++i) {
    adj[i].clear();
    child[i].clear();
    dp[i][0] = dp[i][1] = 0;
    mark[i] = false;
  }
  root->clear();
  n = 0;
}
int main() {
  int test_number;
  scanf("%i", &test_number);
  while (test_number--) {
    int s;
    vector<string> words;
    scanf("%i", &s);
    int answer = 0;
    clear();
    root = new node();
    while (s--) {
      string word;
      cin >> word;
      words.push_back(word);
      root->insert(word, -1);
    }
    for (int i = 0; i < words.size(); ++i) {
      string word = words[i];
      if (word.size() <= 1) {
        continue;
      }
      int current = word[0] - 'a';
      node* main_word = root->child[current];
      insert_edge(main_word, root);
    }
    for (int i = 1; i <= n; ++i) {
      if (!mark[i]) {
        dfs(i);
        solve(i);
        answer += max(dp[i][0], dp[i][1]);
      }
    }
    printf("%i\n", answer);
  }
  return 0;
}
