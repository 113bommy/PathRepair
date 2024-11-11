n = int(input())
s = [int(i) for i in input().split()]
d = {k:0 for k in range(-10,11) if k!=0}
ans = 0
cnt = 0

for i in s:
	if i in d:
		d[i]+=1

for i in d:
	ans+=d[i]*d[-i]
a = s.count(0)
ans//=2
if a>1:
	ans+=((a**2-a)//2)
print(ans)