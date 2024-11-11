n=int(input())
lst=[*map(int,input().split())]
a,b=[],[]
for i,x in enumerate(lst):
    if x>0:a.append(x)
    if x<0:b.append(x)
b.sort()
if len(b)%2==0:a.extend(b)
else:a.extend(b[:-1])
if a==[]:print(max(lst))
else:print(*a)