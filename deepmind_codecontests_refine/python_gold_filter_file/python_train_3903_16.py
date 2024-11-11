n=input()
x=len(n)
ans = (1<<x)-2
for i in range(x):
	if n[x-i-1]=="7":
		ans+=2**i
print(ans+1)	