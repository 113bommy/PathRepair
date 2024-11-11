# your code goes here
def A(n):
	return 2*int(format(n-1,'b'),3)
a = [0]*(100001)
for i in range(1,100000,1):
	a[i] = int(A(i)/2)
a = sorted(a)
for _ in range(int(input())):
	n = int(input())
	for k in a:
		if k>=n:
			print(k)
			break