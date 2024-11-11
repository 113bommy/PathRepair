n = int(input())
a = list(map(int,input().split()))
x = sum(a)
if(n == 1):
	print(-1)
elif(n == 2 and a[0] == a[1]):
	print(-1)
else:
	for i in range(1,n):
		if(x%2 == 1 or sum(a[i:]) != x // 2):
			print(i, end=' ')
			print(*list(range(1,i+1)))
			break