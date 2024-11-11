from sys import stdin
input=stdin.readline
v1=set();a=[-1];s=0
f=int(input())
for i,j in enumerate(map(int,input().split())):
	s+=j
	if j<0 and -j not in v1 or j in v1:exit(print(-1))
	v1.add(j)
	if not s:a+=i,;v1.clear()
if a[-1]!=f-1:exit(print(-1))
print(len(a)-1)
print(*[a[i+1]-a[i] for i in range(len(a)-1)])		