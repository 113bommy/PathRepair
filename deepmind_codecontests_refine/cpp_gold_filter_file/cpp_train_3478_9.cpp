#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int max1[100000];
int max2[100000];
int max3[100000];
int mark1[100000];
int mark2[100000];
int mark3[100000];
int nums[100000];
int main() {
  int n;
  scanf("%d", &n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    nums[i] = k;
    if (k != 0) {
      if (k > max1[m]) {
        max3[m] = max2[m];
        max2[m] = max1[m];
        max1[m] = k;
      } else if (k > max2[m]) {
        max3[m] = max2[m];
        max2[m] = k;
      } else if (k > max3[m])
        max3[m] = k;
    } else {
      m++;
    }
  }
  int count = 3;
  queue<int> qu;
  stack<int> st;
  deque<int> de;
  m = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] != 0) {
      if (count == 3 &&
          (nums[i] == max1[m] || nums[i] == max2[m] || nums[i] == max3[m])) {
        count--;
        qu.push(nums[i]);
        if (nums[i] == max1[m])
          mark1[m] = 1;
        else if (nums[i] == max2[m])
          mark2[m] = 1;
        else if (nums[i] == max3[m])
          mark3[m] = 1;
        printf("pushQueue\n");
      } else if (count == 2 && (nums[i] == max1[m] || nums[i] == max2[m] ||
                                nums[i] == max3[m])) {
        if ((mark1[m] == 0 && nums[i] == max1[m])) {
          mark1[m] = 1;
          count--;
          de.push_front(nums[i]);
          printf("pushFront\n");
        } else if (mark2[m] == 0 && nums[i] == max2[m]) {
          mark2[m] = 1;
          count--;
          de.push_front(nums[i]);
          printf("pushFront\n");
        } else if (mark3[m] == 0 && nums[i] == max3[m]) {
          mark3[m] = 1;
          count--;
          de.push_front(nums[i]);
          printf("pushFront\n");
        } else {
          de.push_back(nums[i]);
          printf("pushBack\n");
        }
      } else if (count == 1 && (nums[i] == max1[m] || nums[i] == max2[m] ||
                                nums[i] == max3[m])) {
        if ((mark1[m] == 0 && nums[i] == max1[m])) {
          mark1[m] = 1;
          count--;
          st.push(nums[i]);
          printf("pushStack\n");
        } else if (mark2[m] == 0 && nums[i] == max2[m]) {
          mark2[m] = 1;
          count--;
          st.push(nums[i]);
          printf("pushStack\n");
        } else if (mark3[m] == 0 && nums[i] == max3[m]) {
          mark3[m] = 1;
          count--;
          st.push(nums[i]);
          printf("pushStack\n");
        } else {
          de.push_back(nums[i]);
          printf("pushBack\n");
        }
      } else {
        de.push_back(nums[i]);
        printf("pushBack\n");
      }
    } else {
      count = 3;
      m++;
      if (qu.size() >= 1 && st.size() >= 1 && de.size() >= 1)
        printf("3 popStack popQueue popFront\n");
      else if (qu.size() >= 1 && st.size() >= 1)
        printf("2 popStack popQueue\n");
      else if (st.size() >= 1 && de.size() >= 1)
        printf("2 popStack popFront\n");
      else if (qu.size() >= 1 && de.size() >= 1)
        printf("2 popQueue popFront\n");
      else if (qu.size() >= 1)
        printf("1 popQueue\n");
      else if (st.size() >= 1)
        printf("1 popStack\n");
      else if (de.size() >= 1)
        printf("1 popFront\n");
      else
        printf("0\n");
      queue<int> q;
      queue<int>().swap(qu);
      de.clear();
      stack<int> s;
      stack<int>().swap(st);
    }
  }
}
