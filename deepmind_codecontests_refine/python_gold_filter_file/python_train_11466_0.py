d={0:[0,0]}
for _ in[0]*int(input()):
 m=c=0
 for x in input():c+=2*(x<')')-1;m=min(m,c)
 d.setdefault((c,-m)[m<0],[0,0])[m<0]+=m in(0,c)
print(sum(map(min,d.values()))+d[0][0]//2)