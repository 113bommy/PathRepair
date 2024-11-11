# ===============================
# (c) MidAndFeed aka ASilentVoice
# ===============================
import math, fractions
n = int(input())
q = [int(x) for x in input().split()]
q.sort()
ans = 1
c = 1
for i in range(1, len(q)):
	if q[i] == q[i-1]:
		c += 1
	else:
		c = 1
	ans = max(ans, c)
print(ans, len(set(q)))