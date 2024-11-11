n=int(input())
li=[int(x) for x in input().split()]
curr=li[0]
cnt=0
sm=sum(li)
for i in range(1,n):
    if curr==(sm-curr):
        cnt+=1
    curr+=li[i]
print(cnt)