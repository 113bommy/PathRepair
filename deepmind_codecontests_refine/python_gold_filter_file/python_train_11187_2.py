n,k = map(int,input().split())
li = list(map(int,input().split()))
nextli = []
alist = sorted(li)
s = 0
r = max(alist)-min(alist)
while True:
	m = li.index(max(alist))
	p = li.index(min(alist))
	li[m] -= 1
	li[p] +=1
	blist = sorted(li)
	l = max(alist)-min(alist)
	if(blist==alist)or(s>=k)or(l>r):
		r = l
		break
	else:
		r = l
		nextli.append(m)
		nextli.append(p)
		alist = blist
		s +=1

print(r,s)
i = 0
while True:
	if(i>=len(nextli)):
		break
	print(nextli[i]+1,nextli[i+1]+1)
	i = i+2
