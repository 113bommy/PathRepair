#include <bits/stdc++.h>
using namespace std;
int pakai[1000005], banyak;
int isi[8 * 1000005], b, a, bagi[1000005];
int best(int x) {
  int jawab = x;
  int indeks = 1;
  int kiri = 1;
  int kanan = b - a;
  while (kiri != kanan) {
    if (isi[indeks] != -1) jawab = min(jawab, isi[indeks]);
    int tengah = (kiri + kanan) / 2;
    if (x <= tengah) {
      kanan = tengah;
      indeks = 2 * indeks;
    } else {
      kiri = tengah + 1;
      indeks = 2 * indeks + 1;
    }
  }
  if (isi[indeks] != -1) jawab = min(jawab, isi[indeks]);
  return jawab;
}
void insert(int kiri, int kanan, int left, int right, int indeks, int j) {
  if (kiri == left && right == kanan) {
    if (isi[indeks] == -1)
      isi[indeks] = j;
    else
      isi[indeks] = min(isi[indeks], j);
  } else {
    int tengah = (left + right) / 2;
    if (kiri <= tengah)
      insert(kiri, min(kanan, tengah), left, tengah, 2 * indeks, j);
    if (kanan > tengah)
      insert(max(kiri, tengah + 1), kanan, tengah + 1, right, 2 * indeks + 1,
             j);
  }
}
int main() {
  scanf("%d", &banyak);
  for (int i = 0; i < banyak; ++i) scanf("%d", &bagi[i]);
  sort(bagi, bagi + banyak);
  scanf("%d %d", &b, &a);
  if (b == a) {
    printf("0\n");
    return 0;
  } else if (b == a + 1) {
    printf("1\n");
    return 0;
  }
  for (int i = 0; i < banyak; ++i) {
    if (i && bagi[i] == bagi[i - 1]) continue;
    int x = a - a % bagi[i];
    if (x < a) x += bagi[i];
    while (x < b) {
      pakai[x - a] = bagi[i];
      x += bagi[i];
    }
  }
  if (pakai[0] > 0) {
    insert(1, min(pakai[0] - 1, b - a), 1, b - a, 1, 1);
  }
  for (int i = 1; i < (b - a); ++i) {
    int j = best(i);
    insert(i + 1, i + 1, 1, b - a, 1, j + 1);
    if (pakai[i] > 0)
      insert(i + 1, min(i + pakai[i] - 1, b - a), 1, b - a, 1, j + 1);
  }
  printf("%d\n", best(b - a));
  return 0;
}
