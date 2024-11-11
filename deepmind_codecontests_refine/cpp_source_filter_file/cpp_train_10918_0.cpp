include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  for (int dataset = 1; dataset <= n; ++dataset) {
    int s;
    scanf("%d", &s);

    printf("Case %d:\n", dataset);
    for (int i = 0; i < 10; ++i) {
      s = s * s;
      s /= 100;
      s %= 10000;
      printf("%d\n", s);
    }
  }
  return 0;
}