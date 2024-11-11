s, v1, v2, t1, t2 = map(int, input().split())
res1 = t1 * 2 + (s * v1)
res2 = t2 * 2 + (s * v2)
if res1 > res2:
	print("Second")
elif res2 > res1:
	print("First")
else:
	print("Friendship")
