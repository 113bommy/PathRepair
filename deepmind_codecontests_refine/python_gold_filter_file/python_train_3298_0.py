n = int(input())
a = list(map(int,input().split()))

mn = 10**10
id = -1
for i in range(n):
	nmn = 0
	if a[i] - i > 0 :
		nmn = 1 + (a[i] - i + n - 1) // n
	
	if nmn < mn :
		mn = nmn
		id = i
print(id + 1)
	