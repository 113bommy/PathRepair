# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math 
# import collections
# import string
# ===================================
n = int(input())
q = [int(x) for x in input().split()]
vmax = -1
for i in range(n-1, -1, -1):
	t = q[i]
	if (q[i] > vmax):
		q[i] = 0
	else:
		q[i] = vmax - q[i] + 1
	vmax = max(vmax, t)
print(" ".join(map(str, q)))