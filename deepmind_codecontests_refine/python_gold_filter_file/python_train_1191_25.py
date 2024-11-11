n=int(input())
a=[int(i) for i in input().split()]
b=[i for i in a]
b.sort()
c=""
fl=[]
for i in range(n):
    if a[i]==b[i]:
        c=c+"1"
    else:
        c=c+"0"
# print(c)
p=c.find("0")
if p==-1:
    p=0
q=c.rfind("0")
if q==-1:
    q=0
# print(p,q)
fl.extend(a[:p])
# print(fl)
f=a[p:q+1]
fl.extend(f[::-1])
# print(fl)
fl.extend(a[q+1:])
# print(fl)
if b==fl:
    print("yes")
    print(p+1,q+1)
else:
    print("no")