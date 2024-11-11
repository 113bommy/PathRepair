#include <bits/stdc++.h>
using namespace std;
int N;
int A[100000];
vector<tuple<int, int, int> > steps;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = N - 1; i >= 2; i--) {
    if (A[i] == 0) {
      continue;
    } else if (i < 6) {
      A[i] = 1 - A[i];
      A[i - 1] = 1 - A[i - 1];
      A[i - 2] = 1 - A[i - 2];
      steps.push_back(make_tuple(i, i - 1, i - 2));
    } else if (A[i - 1] == 1 && A[i - 2] == 1) {
      A[i] = 1 - A[i];
      A[i - 1] = 1 - A[i - 1];
      A[i - 2] = 1 - A[i - 2];
      steps.push_back(make_tuple(i, i - 1, i - 2));
    } else if (A[i - 2] == 1) {
      A[i] = 1 - A[i];
      A[i - 2] = 1 - A[i - 2];
      A[i - 4] = 1 - A[i - 4];
      steps.push_back(make_tuple(i, i - 2, i - 4));
    } else if (A[i - 1] == 0 && A[i - 2] == 0) {
      A[i] = 1 - A[i];
      A[i - 3] = 1 - A[i - 3];
      A[i - 6] = 1 - A[i - 6];
      steps.push_back(make_tuple(i, i - 3, i - 6));
    } else {
      if (i < 10) {
        A[i] = 1 - A[i];
        A[i - 1] = 1 - A[i - 1];
        A[i - 2] = 1 - A[i - 2];
        steps.push_back(make_tuple(i, i - 1, i - 2));
      } else if (A[i - 3] == 0 && A[i - 4] == 0 && A[i - 5] == 0) {
        A[i] = 1 - A[i];
        A[i - 1] = 1 - A[i - 1];
        A[i - 2] = 1 - A[i - 2];
        steps.push_back(make_tuple(i, i - 1, i - 2));
        A[i - 2] = 1 - A[i - 2];
        A[i - 6] = 1 - A[i - 6];
        A[i - 10] = 1 - A[i - 10];
        steps.push_back(make_tuple(i - 2, i - 6, i - 10));
      } else if (A[i - 3] == 1 && A[i - 4] == 0 && A[i - 5] == 0) {
        A[i - 1] = 1 - A[i - 1];
        A[i - 3] = 1 - A[i - 3];
        A[i - 5] = 1 - A[i - 5];
        steps.push_back(make_tuple(i - 1, i - 3, i - 5));
        A[i] = 1 - A[i];
        A[i - 5] = 1 - A[i - 5];
        A[i - 10] = 1 - A[i - 10];
        steps.push_back(make_tuple(i, i - 5, i - 10));
      } else if (A[i - 3] == 0 && A[i - 4] == 1 && A[i - 5] == 0) {
        A[i] = 1 - A[i];
        A[i - 1] = 1 - A[i - 1];
        A[i - 2] = 1 - A[i - 2];
        steps.push_back(make_tuple(i, i - 1, i - 2));
        A[i - 2] = 1 - A[i - 2];
        A[i - 4] = 1 - A[i - 4];
        A[i - 6] = 1 - A[i - 6];
        steps.push_back(make_tuple(i - 2, i - 4, i - 6));
      } else if (A[i - 3] == 0 && A[i - 4] == 0 && A[i - 5] == 1) {
        A[i] = 1 - A[i];
        A[i - 1] = 1 - A[i - 1];
        A[i - 2] = 1 - A[i - 2];
        steps.push_back(make_tuple(i, i - 1, i - 2));
        A[i - 2] = 1 - A[i - 2];
        A[i - 5] = 1 - A[i - 5];
        A[i - 8] = 1 - A[i - 8];
        steps.push_back(make_tuple(i - 2, i - 5, i - 8));
      } else if (A[i - 3] == 1 && A[i - 4] == 1 && A[i - 5] == 0) {
        A[i] = 1 - A[i];
        A[i - 3] = 1 - A[i - 3];
        A[i - 6] = 1 - A[i - 6];
        steps.push_back(make_tuple(i, i - 3, i - 6));
        A[i - 1] = 1 - A[i - 1];
        A[i - 4] = 1 - A[i - 4];
        A[i - 7] = 1 - A[i - 7];
        steps.push_back(make_tuple(i - 1, i - 4, i - 7));
      } else if (A[i - 3] == 1 && A[i - 4] == 0 && A[i - 5] == 1) {
        A[i] = 1 - A[i];
        A[i - 3] = 1 - A[i - 3];
        A[i - 6] = 1 - A[i - 6];
        steps.push_back(make_tuple(i, i - 3, i - 6));
        A[i - 1] = 1 - A[i - 1];
        A[i - 5] = 1 - A[i - 5];
        A[i - 9] = 1 - A[i - 9];
        steps.push_back(make_tuple(i - 1, i - 5, i - 9));
      } else if (A[i - 3] == 0 && A[i - 4] == 1 && A[i - 5] == 1) {
        A[i] = 1 - A[i];
        A[i - 4] = 1 - A[i - 4];
        A[i - 8] = 1 - A[i - 8];
        steps.push_back(make_tuple(i, i - 4, i - 8));
        A[i - 1] = 1 - A[i - 1];
        A[i - 5] = 1 - A[i - 5];
        A[i - 9] = 1 - A[i - 9];
        steps.push_back(make_tuple(i - 1, i - 5, i - 9));
      } else {
        if (i < 13) {
          A[i] = 1 - A[i];
          A[i - 1] = 1 - A[i - 1];
          A[i - 2] = 1 - A[i - 2];
          steps.push_back(make_tuple(i, i - 1, i - 2));
        } else if (A[i - 6] == 0 && A[i - 7] == 0 && A[i - 8] == 0) {
          A[i] = 1 - A[i];
          A[i - 5] = 1 - A[i - 5];
          A[i - 10] = 1 - A[i - 10];
          steps.push_back(make_tuple(i, i - 5, i - 10));
          A[i - 1] = 1 - A[i - 1];
          A[i - 4] = 1 - A[i - 4];
          A[i - 7] = 1 - A[i - 7];
          steps.push_back(make_tuple(i - 1, i - 4, i - 7));
          A[i - 3] = 1 - A[i - 3];
          A[i - 7] = 1 - A[i - 7];
          A[i - 11] = 1 - A[i - 11];
          steps.push_back(make_tuple(i - 3, i - 7, i - 11));
        } else if (A[i - 6] == 1 && A[i - 7] == 0 && A[i - 8] == 0) {
          A[i] = 1 - A[i];
          A[i - 3] = 1 - A[i - 3];
          A[i - 6] = 1 - A[i - 6];
          steps.push_back(make_tuple(i, i - 3, i - 6));
          A[i - 1] = 1 - A[i - 1];
          A[i - 4] = 1 - A[i - 4];
          A[i - 7] = 1 - A[i - 7];
          steps.push_back(make_tuple(i - 1, i - 4, i - 7));
          A[i - 5] = 1 - A[i - 5];
          A[i - 7] = 1 - A[i - 7];
          A[i - 9] = 1 - A[i - 9];
          steps.push_back(make_tuple(i - 5, i - 7, i - 9));
        } else if (A[i - 6] == 0 && A[i - 7] == 1 && A[i - 8] == 0) {
          A[i - 1] = 1 - A[i - 1];
          A[i - 3] = 1 - A[i - 3];
          A[i - 5] = 1 - A[i - 5];
          steps.push_back(make_tuple(i - 1, i - 3, i - 5));
          A[i] = 1 - A[i];
          A[i - 4] = 1 - A[i - 4];
          A[i - 8] = 1 - A[i - 8];
          steps.push_back(make_tuple(i, i - 4, i - 8));
          A[i - 7] = 1 - A[i - 7];
          A[i - 8] = 1 - A[i - 8];
          A[i - 9] = 1 - A[i - 9];
          steps.push_back(make_tuple(i - 7, i - 8, i - 9));
        } else if (A[i - 6] == 0 && A[i - 7] == 0 && A[i - 8] == 1) {
          A[i - 1] = 1 - A[i - 1];
          A[i - 3] = 1 - A[i - 3];
          A[i - 5] = 1 - A[i - 5];
          steps.push_back(make_tuple(i - 1, i - 3, i - 5));
          A[i] = 1 - A[i];
          A[i - 4] = 1 - A[i - 4];
          A[i - 8] = 1 - A[i - 8];
          steps.push_back(make_tuple(i, i - 4, i - 8));
        } else if (A[i - 6] == 1 && A[i - 7] == 1 && A[i - 8] == 0) {
          A[i] = 1 - A[i];
          A[i - 3] = 1 - A[i - 3];
          A[i - 6] = 1 - A[i - 6];
          steps.push_back(make_tuple(i, i - 3, i - 6));
          A[i - 1] = 1 - A[i - 1];
          A[i - 4] = 1 - A[i - 4];
          A[i - 7] = 1 - A[i - 7];
          steps.push_back(make_tuple(i - 1, i - 4, i - 7));
          A[i - 5] = 1 - A[i - 5];
          A[i - 9] = 1 - A[i - 9];
          A[i - 13] = 1 - A[i - 13];
          steps.push_back(make_tuple(i - 5, i - 9, i - 13));
        } else if (A[i - 6] == 1 && A[i - 7] == 0 && A[i - 8] == 1) {
          A[i] = 1 - A[i];
          A[i - 4] = 1 - A[i - 4];
          A[i - 8] = 1 - A[i - 8];
          steps.push_back(make_tuple(i, i - 4, i - 8));
          A[i - 1] = 1 - A[i - 1];
          A[i - 3] = 1 - A[i - 3];
          A[i - 5] = 1 - A[i - 5];
          steps.push_back(make_tuple(i - 1, i - 3, i - 5));
          A[i - 6] = 1 - A[i - 6];
          A[i - 9] = 1 - A[i - 9];
          A[i - 12] = 1 - A[i - 12];
          steps.push_back(make_tuple(i - 6, i - 9, i - 12));
        } else if (A[i - 6] == 0 && A[i - 7] == 1 && A[i - 8] == 1) {
          A[i] = 1 - A[i];
          A[i - 4] = 1 - A[i - 4];
          A[i - 8] = 1 - A[i - 8];
          steps.push_back(make_tuple(i, i - 4, i - 8));
          A[i - 1] = 1 - A[i - 1];
          A[i - 4] = 1 - A[i - 4];
          A[i - 7] = 1 - A[i - 7];
          steps.push_back(make_tuple(i - 1, i - 4, i - 7));
          A[i - 3] = 1 - A[i - 3];
          A[i - 4] = 1 - A[i - 4];
          A[i - 5] = 1 - A[i - 5];
          steps.push_back(make_tuple(i - 3, i - 4, i - 5));
        } else if (A[i - 6] == 1 && A[i - 7] == 1 && A[i - 8] == 1) {
          A[i] = 1 - A[i];
          A[i - 3] = 1 - A[i - 3];
          A[i - 6] = 1 - A[i - 6];
          steps.push_back(make_tuple(i, i - 3, i - 6));
          A[i - 1] = 1 - A[i - 1];
          A[i - 4] = 1 - A[i - 4];
          A[i - 7] = 1 - A[i - 7];
          steps.push_back(make_tuple(i - 1, i - 4, i - 7));
          A[i - 5] = 1 - A[i - 5];
          A[i - 8] = 1 - A[i - 8];
          A[i - 11] = 1 - A[i - 11];
          steps.push_back(make_tuple(i - 5, i - 8, i - 11));
        }
      }
    }
  }
  if (A[0] == 0 && A[1] == 0) {
    printf("YES\n");
    printf("%d\n", steps.size());
    for (int i = 0; i < steps.size(); i++) {
      printf("%d %d %d\n", get<0>(steps[i]) + 1, get<1>(steps[i]) + 1,
             get<2>(steps[i]) + 1);
    }
    return 0;
  }
  if (A[0] == 0) {
    if (N < 8) {
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    printf("%d\n", steps.size() + 3);
    for (int i = 0; i < steps.size(); i++) {
      printf("%d %d %d\n", get<0>(steps[i]) + 1, get<1>(steps[i]) + 1,
             get<2>(steps[i]) + 1);
    }
    printf("%d %d %d\n", 2, 5, 8);
    printf("%d %d %d\n", 5, 6, 7);
    printf("%d %d %d\n", 6, 7, 8);
    return 0;
  }
  if (A[1] == 0) {
    if (N < 7) {
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    printf("%d\n", steps.size() + 3);
    for (int i = 0; i < steps.size(); i++) {
      printf("%d %d %d\n", get<0>(steps[i]) + 1, get<1>(steps[i]) + 1,
             get<2>(steps[i]) + 1);
    }
    printf("%d %d %d\n", 1, 4, 7);
    printf("%d %d %d\n", 4, 5, 6);
    printf("%d %d %d\n", 5, 6, 7);
    return 0;
  }
  if (A[0] == 1 && A[1] == 1) {
    if (N < 8) {
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    printf("%d\n", steps.size() + 4);
    for (int i = 0; i < steps.size(); i++) {
      printf("%d %d %d\n", get<0>(steps[i]) + 1, get<1>(steps[i]) + 1,
             get<2>(steps[i]) + 1);
    }
    printf("%d %d %d\n", 1, 4, 7);
    printf("%d %d %d\n", 2, 5, 8);
    printf("%d %d %d\n", 4, 5, 6);
    printf("%d %d %d\n", 6, 7, 8);
    return 0;
  }
}
