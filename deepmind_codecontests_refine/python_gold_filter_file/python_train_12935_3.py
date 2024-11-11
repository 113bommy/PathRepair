n = int(input())
lis = list(map(int, input().split()))
bits = [0]*20

for num in lis:
	for i in range(20):
		bits[i] += (num>>i)&1

sq = 0
for i in range(n):
	cur = 0
	for j in range(20):
		if bits[j]>0:
			cur+=(1<<j)
			bits[j]-=1
	if cur>0:
		sq += cur**2
print(sq)