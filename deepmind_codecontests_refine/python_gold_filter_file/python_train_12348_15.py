n=int(input())
l=[]
l= [int(x) for x in input().split()]
l.sort()
s=l[n]
t=[]
for i in range(n):
 t.append(l[i])
if s not in t:
 print("YES")
else:
 print("NO")
