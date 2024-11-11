# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math, fractions, collections
# ===================================
n, k = [int(x) for x in input().split()]
q = [int(x) for x in input().split()]
q.sort()
ans = 0
k *= 2
for x in q:
	while(x > k):
		k *= 2
		ans += 1
	k = max(2*x, k)
print(ans)