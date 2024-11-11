n=int(input())
for i in range(n):
	k=input()
	k=sorted(k)
	if k[0]==k[-1]:
		print(-1)
	else:
		print("".join(k))