ans=[]
l=sorted(list(map(int,input().split())))
l.pop()
for i in range(3):
    temp=int((l[0]+l[1]-l[2])/2)
    l.append(l.pop(0))
    ans.append(temp)
print(*ans)