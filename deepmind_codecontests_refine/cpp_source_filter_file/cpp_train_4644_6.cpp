#include <bits/stdc++.h>
using namespace std;
long long int powa(long long int x, long long int y) {
  long long int ans = 1;
  long long int m = 1e9 + 7;
  while (y > 0) {
    if (y % 2 == 1) {
      ans *= x;
      ans %= m;
    }
    y /= 2;
    x = x * x;
    x %= m;
  }
  return ans % m;
}
int a[100005];
struct TrieNode {
  int value, cnt;
  TrieNode *arr[2];
};
TrieNode *newNode() {
  TrieNode *temp = new TrieNode;
  temp->value = -1;
  temp->arr[0] = temp->arr[1] = NULL;
  temp->cnt = 0;
  return temp;
}
bool find(TrieNode *root, int pre_xor);
void insert(TrieNode *root, int pre_xor, bool dw = 0) {
  if (!dw && find(root, pre_xor)) {
    return;
  }
  TrieNode *temp = root;
  for (int i = 32 - 1; i >= 0; i--) {
    temp->cnt++;
    bool val = pre_xor & (1 << i);
    if (temp->arr[val] == NULL) temp->arr[val] = newNode();
    temp = temp->arr[val];
  }
  temp->value = pre_xor;
  temp->cnt++;
}
bool find(TrieNode *root, int pre_xor) {
  TrieNode *temp = root;
  for (int i = 32 - 1; i >= 0; i--) {
    bool val = pre_xor & (1 << i);
    if (temp->arr[val] == NULL) return false;
    temp = temp->arr[val];
  }
  return true;
}
void remove(TrieNode *root, int vala) {
  TrieNode *temp = root;
  temp->cnt--;
  int i = 32 - 1;
  for (; i >= 0; i--) {
    bool val = vala & (1 << (i));
    temp->arr[val]->cnt--;
    if (temp->arr[val]->cnt == 0) {
      temp->arr[val] = NULL;
      break;
    }
    temp = temp->arr[val];
  }
}
int xora(TrieNode *root, int xoro) {
  TrieNode *temp = root;
  int ansa = 0;
  for (int i = 32 - 1; i >= 0; i--) {
    bool val = xoro & (1 << (i));
    if (temp->arr[val] == NULL) {
      break;
    }
    if (temp->arr[val]->cnt != ((1LL << (i)))) {
      temp = temp->arr[val];
      continue;
    } else if (temp->arr[1 - val] == NULL) {
      ansa += (1 << i);
      break;
    } else {
      temp = temp->arr[1 - val];
      ansa += (1 << i);
    }
  }
  return ansa;
}
int findgreaterthanequalto(TrieNode *root, int xoro, int k) {
  TrieNode *temp = root;
  int ansa = 0;
  int i = 32 - 1;
  for (; i >= 0; i--) {
    bool val = xoro & (1 << i);
    bool kval = k & (1 << i);
    if (kval == 0) {
      if (temp->arr[1 - val ^ kval] != NULL)
        ansa += temp->arr[1 - val ^ kval]->cnt;
    }
    if (temp->arr[val ^ kval] == NULL) break;
    temp = temp->arr[val ^ kval];
  }
  if (i == -1) ansa += temp->cnt;
  return ansa;
}
int main() {
  int q;
  cin >> q;
  TrieNode *root = newNode();
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      insert(root, x);
    }
    if (op == 2) {
      int x;
      cin >> x;
      remove(root, x);
    } else if (op == 3) {
      int x, y;
      cin >> x >> y;
      cout << root->cnt - findgreaterthanequalto(root, x, y) << "\n";
    }
  }
  return 0;
}
