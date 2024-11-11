N = int(input())
a = input().split()
for i in range(0,N):
	a[i] = int(a[i])
a.sort()
t = 0
flag = 1
sum_a = 0
for i in range(0,N-1):
	sum_a += a[i]
	if sum_a*2 < a[i+1]:
		t = i+1

			
print(N-t)