n,m = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
sum1 = sum(a)
delete = n
possible_height = 0
max_height = a[n-1]
for i in range(n):
	if a[i]>possible_height:
		possible_height+=1

print(sum1-delete+possible_height-max_height)