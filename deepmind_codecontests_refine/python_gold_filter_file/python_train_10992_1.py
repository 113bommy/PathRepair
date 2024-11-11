s = list(input())

p=[1]
for i in range(1000000):
	p.append((p[i]*2)%1000000007)

ctr=0
ans=0
l = len(s)
for i in range(l):
	if s[i]=='a':
		ctr+=1
		continue
	ans=(p[ctr]-1+ans)%1000000007

print(ans)