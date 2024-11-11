a=[]
for i in range(int(input())):
    x,y=map(int, input().split())
    a.append((x,1))
    a.append((y,0))
a.sort()
k=ans=curr=0
for i in a:
    if i[1]==1:
        curr+=1
    else:
        curr-=1
    if k<curr:
        k=curr
        ans=i[0]
print(ans, k)

    