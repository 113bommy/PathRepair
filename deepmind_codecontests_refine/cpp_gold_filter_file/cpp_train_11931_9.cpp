#include <bits/stdc++.h>
int A, B, L, R;
bool found[1000];
bool seen[1000];
void InitialSegment() {
  if (R <= A) {
    printf("%d\n", R - L + 1);
    std::exit(0);
  }
}
void SameRange() {
  if (L <= A) {
    return;
  }
  int bucket_1 = (L - A - 1) / (A + B);
  int bucket_2 = (R - A - 1) / (A + B);
  if (bucket_1 == bucket_2) {
    int x1 = (L - A - 1) % (A + B);
    int x2 = (R - A - 1) % (A + B);
    if (x1 < B && x2 < B) {
      printf("1\n");
      std::exit(0);
    } else if (x1 >= B && x2 >= B) {
      printf("%d\n", R - L + 1);
      std::exit(0);
    } else {
      printf("%d\n", 2 + (R - A - 1) % (A + B) - B);
      std::exit(0);
    }
  }
}
void RangeWithoutInitial() {
  if (L <= A) return;
  int bucket_1 = (L - A - 1) / (A + B);
  int bucket_2 = (R - A - 1) / (A + B);
  if (bucket_2 - bucket_1 > 1) {
    if (B >= A) {
      printf("%d\n", A + 1);
      std::exit(0);
    } else {
      printf("%d\n", A + A - B);
      std::exit(0);
    }
  }
  int where_1 = (L - A - 1) % (A + B);
  int where_2 = (R - A - 1) % (A + B);
  int part_1, part_2;
  if (where_1 < B) {
    part_1 = 0;
  } else {
    part_1 = 1;
  }
  if (where_2 < B) {
    part_2 = 0;
  } else {
    part_2 = 1;
  }
  if (part_1 == 0 && part_2 == 0) {
    printf("%d\n", A + 1);
    std::exit(0);
  }
  if (part_1 == 0 && part_2 == 1) {
    if (B >= A) {
      printf("%d\n", A + 1);
      std::exit(0);
    } else {
      int x = where_2 - B + 1;
      if (x <= B) {
        printf("%d\n", A + 1);
        std::exit(0);
      } else {
        printf("%d\n", A + x - B);
        std::exit(0);
      }
    }
  }
  if (part_1 == 1 && part_2 == 0) {
    int x1 = A + B - where_1;
    printf("%d\n", x1);
    std::exit(0);
  }
  if (part_1 == 1 && part_2 == 1) {
    int x1 = A + B - where_1;
    int x2 = where_2 - B + 1;
    printf("%d\n", std::min(x1 + x2, A + 1));
    std::exit(0);
  }
}
void RangeWithInitial() {
  int x1 = A - L + 1;
  int bucket_2 = (R - A - 1) / (A + B);
  if (bucket_2 > 1) {
    if (B >= A) {
      printf("%d\n", A + 1);
      std::exit(0);
    } else {
      printf("%d\n", A + A - B);
      std::exit(0);
    }
  }
  int where_2 = (R - A - 1) % (A + B);
  int part_2;
  if (where_2 < B) {
    part_2 = 0;
  } else {
    part_2 = 1;
  }
  if (part_2 == 0) {
    printf("%d\n", x1);
    std::exit(0);
  } else {
    char s[1000];
    for (int i = 0; i < A; i++) {
      s[i] = 'a' + i;
    }
    for (int i = A; i < A + B; i++) {
      s[i] = 'a' + A - 1;
    }
    for (int i = A + B - 1, j = 1; j <= A; i--, j++) {
      seen[s[i]] = true;
    }
    for (int i = A + B, j = 0; i < 2 * A + B; i++) {
      while (seen['a' + j]) {
        j++;
      }
      s[i] = 'a' + j;
      j++;
    }
    int sol = 0;
    for (int i = L - 1; i <= R - 1; i++) {
      if (!found[s[i]]) {
        sol++;
        found[s[i]] = true;
      }
    }
    printf("%d\n", sol);
  }
}
int main() {
  scanf("%d%d%d%d", &A, &B, &L, &R);
  InitialSegment();
  SameRange();
  RangeWithoutInitial();
  RangeWithInitial();
  return 0;
}
