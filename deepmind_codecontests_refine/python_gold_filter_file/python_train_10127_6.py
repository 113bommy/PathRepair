input=__import__('sys').stdin.readline
def check(*inds):
	global localmax, localmin, maxs, mins
	for ind in inds:
		if not ok(ind):continue
		if localmax[ind]==0 and s[ind-1]<s[ind]>s[ind+1]:localmax[ind]=1;maxs+=s[ind]
		if localmin[ind]==0 and s[ind-1]>s[ind]<s[ind+1]:localmin[ind]=1;mins+=s[ind]
def upd0(*inds):
	global localmax, localmin, maxs, mins
	for ind in inds:
		if not ok(ind):continue
		if localmax[ind]:localmax[ind]=0;maxs-=s[ind]
		if localmin[ind]:localmin[ind]=0;mins-=s[ind]
def ok(ind):return 0<=ind-1<=ind+1<=n
ans=[]
for _ in range(int(input())):
	n,q=map(int,input().split());n+=1
	s=[0]+list(map(int,input().split()))+[0]
	localmax=[0]*n
	localmin=[0]*n
	maxs=mins=0
	for i in range(n):
		check(i)
	ans.append(maxs-mins)
	for _ in range(q):
		l,r=map(int,input().split())
		upd0(l,l-1,l+1,r,r-1,r+1)
		s[l],s[r]=s[r],s[l]
		check(l,l-1,l+1,r,r-1,r+1)
		ans.append(maxs-mins)
print(*ans,sep='\n')