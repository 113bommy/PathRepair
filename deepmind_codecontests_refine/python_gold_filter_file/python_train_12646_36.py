a=int(input())
b=input()
b=b.lower()
c=[]
for i in b:
    c.append(i)
c=list(set(c))
if len(c)<26:
    print("NO")
else:
    print("YES")
