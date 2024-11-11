n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))[::-1]
j = 0
for i in range(n):
	if a[i]==0:
		a[i]=b[j]
		j+=1
if a==sorted(a) and k==1:
	print("No")
else:
	print("Yes") 