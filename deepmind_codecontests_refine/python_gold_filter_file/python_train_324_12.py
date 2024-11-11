x=int(input())
y=[int(x) for x in input().split()]
a=[]
b=[]
for i in y:
    if i%2==0:
        a.append(i)
    else:
        b.append(i)
aa=len(a)
a=sorted(a)
bb=len(b)
b=sorted(b)
if len(a)==len(b) or aa==bb+1 or bb==aa+1:
    print(0)
elif len(a)==0:
    b.pop()
    print(sum(b))
elif len(b)==0:
    a.pop()
    print(sum(a))
elif len(a)>len(b):
    for i in range(bb+1):
        a.pop()
    print(sum(a))
elif len(b)>len(a):
    for i in range(aa+1):
        b.pop()
    print(sum(b))

    
    