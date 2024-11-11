n = int(input())
ns = input().split()
for i in range(len(ns)):
	ns[i] = int(ns[i])
s = 0
avg = (sum(ns)/n)
if avg == int(avg):
	cv = 0
else:
	cv=1
	avg = int(avg)
pc = 0
nc = 0
ipc = 0
inc = 0
for i in range(n):
	diff = ns[i]-avg
	if abs(diff)>cv:
		if diff>0:
			pc = pc+diff-cv
		else:
			nc = nc+abs(diff)-cv
	if cv==1:
		if diff>=1:
			ipc = ipc+1
		elif diff <= -1:
			inc = inc+1
# if ns[0]==1474:
# 	print(pc,nc,ipc,inc,sum(ns)/n,len(ns))
bse = min([pc,nc])
s = int(bse+abs(pc-nc))
pc = pc - bse
nc = nc - bse
ipc = ipc - nc
inc = inc - pc
if ipc>0 and inc>0:
	s = int(s+min([ipc,inc]))
print(s)