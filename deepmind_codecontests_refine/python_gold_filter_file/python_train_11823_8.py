d=[]
anz=0
a,b,c = [int(x) for x in input().split()]
d.append(a)
d.append(b)
d.append(c)

d.sort()
anz=d[2]-d[0]
print(anz,end="\n")
