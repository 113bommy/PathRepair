#include <bits/stdc++.h>
using namespace std;
typedef struct data {
  long long d;
  long long e;
  long long f;
} data;
typedef struct node {
  int leftEnd;
  int rightEnd;
  data ans;
  node *leftChild;
  node *rightChild;
} node;
int n;
long long a[100001], baseAns;
node *root;
data GetData(int i) {
  data ans;
  if (i == 0 || i == 1 || i == n) {
    ans.d = -LLONG_MAX / 2;
    ans.e = -LLONG_MAX / 2;
    ans.f = -LLONG_MAX / 2;
  } else {
    long long d = abs(a[i - 1]) + abs(a[i]);
    ans.d = a[i - 1] - a[i] - d;
    ans.e = -a[i - 1] - a[i] - d;
    ans.f = -a[i - 1] + a[i] - d;
  }
  return ans;
}
data Combine(data a, data b) {
  data ans;
  ans.d = max(a.d, b.d);
  ans.e = max(a.e, b.e);
  ans.f = max(a.f, b.f);
  return ans;
}
node *BuildSegmentTree(int leftEnd, int rightEnd) {
  node *temp = new node;
  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  if (leftEnd != rightEnd) {
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->ans = Combine(temp->leftChild->ans, temp->rightChild->ans);
  } else {
    temp->ans = GetData(leftEnd);
    temp->leftChild = temp->rightChild = NULL;
  }
  return temp;
}
void Update(node *currentNode, int i) {
  if (i < currentNode->leftEnd || currentNode->rightEnd < i)
    return;
  else {
    if (i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->ans = GetData(i);
    else {
      Update(currentNode->leftChild, i);
      Update(currentNode->rightChild, i);
      currentNode->ans =
          Combine(currentNode->leftChild->ans, currentNode->rightChild->ans);
    }
  }
}
data Query(node *currentNode, int l, int r) {
  if (r < l || r < currentNode->leftEnd || currentNode->rightEnd < l) {
    return GetData(0);
  } else {
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);
    if (l == currentNode->leftEnd && currentNode->rightEnd == r)
      return currentNode->ans;
    else
      return Combine(Query(currentNode->leftChild, l, r),
                     Query(currentNode->rightChild, l, r));
  }
}
void Update(int l, int r, int x) {
  if (l > 1) {
    baseAns += (abs(a[l - 1] - x) - abs(a[l - 1]));
    a[l - 1] -= x;
    Update(root, l - 1);
    Update(root, l);
  }
  if (r < n) {
    baseAns += (abs(a[r] + x) - abs(a[r]));
    a[r] += x;
    Update(root, r);
    Update(root, r + 1);
  }
}
long long Query(int l, int r, int x) {
  data ans = Query(root, l + (l == 1), r - (r == n));
  long long delta = max(ans.e, max(ans.d - x - x, ans.f + x + x));
  if (l == 1) {
    delta = max(delta, abs(a[l] + x) - abs(a[l]));
  }
  if (r == n) {
    delta = max(delta, abs(a[r - 1] - x) - abs(a[r - 1]));
  }
  return baseAns + delta;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i < n; ++i) {
    a[i] -= a[i + 1];
    baseAns += abs(a[i]);
  }
  root = BuildSegmentTree(1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r, x;
    scanf("%d%d%d%d", &t, &l, &r, &x);
    if (t == 1)
      printf("%lld\n", Query(l, r, x));
    else
      Update(l, r, x);
  }
  return 0;
}
