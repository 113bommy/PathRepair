n=int(input())
s=input()
a=set()
ans=0
for i in s:
	if i.islower():
		a.add(i)
		ans=max(ans,len(a))
	else:
		a.clear()
print(ans)