import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
av1,av2,av3=set(),set(),set()
ans,f,i=[],0,n-1
for j in range(n-1,-1,-1):
	if a[j]==1:
		av1.add((i,j))
		ans.append((i,j))
	elif a[j]==2:
		if av1:
			ii,jj=av1.pop()
			av2.add((ii,j))
			ans.append((ii,j))
		else:
			f=1;break
	elif a[j]==3:
		if av3:
			ii,jj=av3.pop()
		elif av2:
			ii,jj=av2.pop()
		elif av1:
			ii,jj=av1.pop()
		else:
			f=1;break
		av3.add((i,j))
		ans.append((i,jj))
		ans.append((i,j))
	i-=1
if f:
	print(-1)
else:
	if ans:
		print(len(ans))
		for i,j in ans:
			print(i+1,j+1)
	else:print(0)