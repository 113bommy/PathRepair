n,m=[int(i) for i in input().split()]
list=[]
for j in input().split():
    list.append(int(j))
list.sort()
if m!=n:
    minus=[]
    for i in range(m-n+1):
        minus.append(list[i+n-1]-list[i])
    print(min(minus))
else:
    print(list[m-1]-list[0])
