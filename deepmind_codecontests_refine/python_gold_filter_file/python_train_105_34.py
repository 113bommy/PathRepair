c=[s+' '+str(i)for s in'SHCD'for i in range(1,14)]
for _ in range(int(input())):
 c.remove(input())
if[]!=c:print(*c,sep='\n')