import sys
import itertools as it
import math as mt
import collections as cc
import bisect as bi
I=lambda:list(map(int,input().split()))
n,k=I()
l=I()
ar=[]
f=cc.defaultdict(list)
ch=cc.defaultdict(int)
for i in range(n):
	ar.append([l[i],i])
	f[l[i]].append(i)
ar.sort(key=lambda x:x[0])
if l.count(0)>1:
	print(-1)
elif 0 not in l:
	print(-1)
else:
	d=max(l)
	ed=[]
	now=0;
	prev=[l.index(0)]
	tf=1

	while now+1<=d:
		cur=set()
		if len(f[now+1])==0:
			tf=0
			break
		ii=0
		ll=len(prev)
		if ll*k<len(f[now+1]):
			tf=0
			break
		else:
			for j in f[now+1]:
				if ch[prev[ii]]<k:
					#print(1,ch,prev[ii])
					ch[prev[ii]]+=1
					ch[j]+=1
					cur.add(j)
					ed.append([prev[ii]+1,j+1])
					ii+=1
					ii%=ll
				else:
					tf=0
					break
		#print(2,ch)
		prev=list(cur)
		now+=1
	if not tf:
		print(-1)
	else:
		print(len(ed))
		for i in ed:
			print(*i)