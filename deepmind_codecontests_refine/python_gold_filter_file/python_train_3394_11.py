#!/usr/bin/env python3

from collections import defaultdict
import sys

[n, A] = map(int, input().strip().split())
cis = list(map(int, input().strip().split()))

cnt = defaultdict(int)
cA = 0
for c in cis:
	if c == A:
		cA += 1
	else:
		cnt[c] += 1
		if cnt[c] <= cA:
			cnt[c] = -2

for k, v in cnt.items():
	if v >= cA:
		print (k)
		sys.exit()


print (-1)
