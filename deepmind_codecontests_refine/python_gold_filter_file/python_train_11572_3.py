n=int(input())
l=list(input())
r=list(input())
d={chr(97+i):[] for i in range(26)}
e={chr(97+i):[] for i in range(26)}
d['?']=[]
e['?']=[]
for i in range(n):
    d[l[i]].append(i+1)
for i in range(n):
    e[r[i]].append(i+1)
count=0

c=[]
for i in d.keys():
    if i!='?':
        for j in range(min(len(d[i]),len(e[i]))):
            c.append([d[i].pop(),e[i].pop()])
for i in d.keys():
    x=min(len(e['?']),len(d[i]))
    for j in range(x):
        c.append([d[i].pop(),e['?'].pop()])
for i in e.keys():
    x=min(len(e[i]),len(d['?']))
    for j in range(x):
        c.append([d['?'].pop(),e[i].pop()])
print(len(c))
for i in range(len(c)):
    print(*c[i])
            
