#!/usr/bin/env python3
n, *a = map(int, open(0).read().split())
a.sort(reverse=1)
print(sum(a[:0--n // 2]) * 2 - max(a) - a[n // 2] * (n % 2))