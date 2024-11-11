n=int(input())
sost=now=''
res=0
cond={'UR','RD','DL','LU','RU','DR','LD','UL'}
for i in input():
	now+=i
	if len(now)==1:
		continue
	if len(now)==2:
		if now[1]==now[0]:
			now=now[1:]
			continue
		if now in cond:
			if sost!='' and (sost[:]!=now and sost[-1::-1]!=now):
				res+=1
				sost=''
				now=now[1:]
			else:
				sost=now
				now=now[1:]
		else:
			res+=1
			sost=''
			now=now[1:]
print(res+1)
