def show(x, y, z, w):
	print("YES")
	print(x+1, y+1, z+1, w+1)
	exit(0)

n=int(input())
ara=list(int(x) for x in input().split())

n=min(n, 2000)
found={}
for i in range(0, n):
	for j in range(i+1, n):
		cur_sm=ara[i]+ara[j]
		if cur_sm in found.keys() and found[cur_sm][0]!=i and found[cur_sm][1]!=j and found[cur_sm][0]!=j and found[cur_sm][1]!=i:
			show(found[cur_sm][0], found[cur_sm][1], i, j);

		found[cur_sm]=(i, j)

print("NO")