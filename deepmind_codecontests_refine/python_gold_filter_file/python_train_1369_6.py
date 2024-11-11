
n = int(input())

x = list(map(int, str(input()).split()))

r = 0
maxi = 0
for i in range(n):
	if maxi < x[i]:
		maxi = x[i]
	if maxi <= i+1:
		r+=1
		maxi = 0

print(r)
