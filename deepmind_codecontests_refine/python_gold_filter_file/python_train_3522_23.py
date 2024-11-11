n = int(input())
T = [0]*n
c,s,f = [0]*(n-1),[0]*(n-1),[0]*(n-1)
 
for i in range(n-1):
	c[i],s[i],f[i] = map(int,input().split())

for	i in range(n-1):
	T[i] = s[i] + c[i]
	for j in range(i+1,n-1):
		if T[i] > s[j]:
			T[i] += (-T[i])%f[j] + c[j]
		else:
			T[i] = s[j] + c[j]
	print(T[i])
print(0)