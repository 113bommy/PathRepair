ii=lambda:int(input())
kk=lambda:map(int,input().split())
ll=lambda:list(kk())
def pow(base,exp):
	if exp==0:return 1
	if exp==1:return base
	res=pow(base,exp//2)
	res*=res
	if exp&1: res*=base
	return res%mod

h,w=kk()
hs,ws=kk(),kk()
grid=[[-1]*w for _ in range(h)]
for i,hv in enumerate(hs):
	for j in range(hv):
		grid[i][j]=1
	if hv<w: grid[i][hv]=0
for j,wv in enumerate(ws):
	for i in range(wv):
		if grid[i][j] == 0:
			print(0)
			exit()
		grid[i][j]=1
	if wv<h:
		if grid[wv][j] == 1:
			print(0)
			exit()
		grid[wv][j]=0
c=0
for i in range(h):
	for j in range(w):
		if grid[i][j]==-1:c+=1
ans = 1
mod=10**9+7
print(pow(2,c))