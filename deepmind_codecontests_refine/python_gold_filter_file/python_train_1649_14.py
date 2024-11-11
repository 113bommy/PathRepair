n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

m = 0

for i in range(n):
	m = max(m, sum(a[0:i+1])+sum(b[i:n]))
	
print(m)