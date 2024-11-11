from collections import Counter
n,q=[int(_) for _ in input().split()]
s=input()
ps=[0]
for i in s:
    ps.append(ps[-1]+ord(i)-96)
#print(ps)    
for t in range(q):
    l,r=[int(_) for _ in input().split()]
    print(ps[r]-ps[l-1])
