#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e8;
struct nod {
  int level;
  nod* emps;
  nod* mang;
};
class node {
 public:
  int data;
  node* right;
  node(int d) {
    data = d;
    right = NULL;
  }
};
bool first = false;
node* buildtree(int n) {
  if (n == 0) return NULL;
  int d;
  cin >> d;
  node* root;
  if (d == -1 && first == true) {
    return NULL;
  }
  if (d == -1) first = true;
  root = new node(d);
  root->right = buildtree(n - 1);
  return root;
}
void print(node* root) {
  if (root == NULL) return;
  cout << root->data << " ";
  print(root->right);
}
int main() {
  int r, c;
  bool wolf = false;
  cin >> r >> c;
  char arr[r][c];
  for (int i = 0; i < r; i++) {
    for (int u = 0; u < c; u++) {
      cin >> arr[i][u];
      if (arr[i][u] == 'W')
        wolf = true;
      else if (arr[i][u] == '.')
        arr[i][u] = 'D';
    }
  }
  if (wolf == false) {
    cout << "Yes\n";
    for (int i = 0; i < r; i++) {
      for (int u = 0; u < c; u++) {
        cout << arr[i][u];
      }
      cout << endl;
    }
    return 0;
  }
  for (int i = 0; i < r; i++) {
    for (int u = 0; u < c; u++) {
      if (arr[i][u] == 'S') {
        if ((i - 1 >= 0 && arr[i - 1][u] == 'W') ||
            (i + 1 < r && arr[i + 1][u] == 'W') ||
            (u - 1 >= 0 && arr[i][u - 1] == 'W') ||
            (u + 1 < c && arr[i][u + 1] == 'W')) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < r; i++) {
    for (int u = 0; u < c; u++) {
      cout << arr[i][u];
    }
    cout << endl;
  }
  return 0;
}
