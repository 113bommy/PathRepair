n=int(input())
prev=None
ans=False
nodes={}
for i in "abcdefghijklmnopqrstuvwxyz":
    nodes[i]=set()
for i in range(n):
    name=input()
    if prev:
        for x,y in zip(name,prev):
            if x!=y:
                nodes[x].add(y)
                break
        else:
                if prev>name:
                    ans=True
                    break
    prev=name
a=[]
b=[]
for i in "abcdefghijklmnopqrstuvwxyz":
    if not nodes[i]:
        a.append(i)
    else:
        b.append(i)
c=[]
while a:
    d=a.pop()
    c.append(d)
    for i in b[:]:
        if d in nodes[i]:
            nodes[i].remove(d)
            if not nodes[i]:
                a.append(i)
                b.remove(i)
if b or ans:
    print("Impossible")
else:
    print("".join(c))