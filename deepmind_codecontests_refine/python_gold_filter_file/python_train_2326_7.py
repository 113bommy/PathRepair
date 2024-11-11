d = int(input())
n = int(input())
a = list(map(int,input().split()))
count = 0
for i in range(n-1):
	count += d-a[i]
print(count)