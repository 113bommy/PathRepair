h,w,k=map(int,input().split())
Cho=[list(map(int,list(input()))) for _ in range(h)]
ans=10000000
for i in range(2**(h-1)):
	need=0
	seq=[]
	t=[]
	for j in range(h-1):
		t.append(j)
		if i&(1<<j):
			need+=1
			seq.append(t)
			t=[]
	seq.append(t+[h-1])
	f=1
	q=need+1
	cnt=[0]*q
	for x in range(w):
		cntp=[0]*q
		for i,g in enumerate(seq):
			cntg=0
			for y in g:
				cntg+=Cho[y][x]
				if cntg>k:
					f=0
					break
				cntp[i]+=Cho[y][x]
			if not f:
				break
		if not f:
			break
		for xx in range(q):
			cnt[xx]+=cntp[xx]
		if any(xxx>k for xxx in cnt):
			need+=1
			if need>ans:
				f=0
				break
			cnt=cntp
	if f:
		ans=min(ans,need)
print(ans)
