n,x,y=map(int,input().split())
l=input()
l=l[len(l)-x-1:len(l)]
ans=0
if int(l[len(l)-y-1])!=1:
    ans+=1
    ans += l[1:len(l)].count('1')
else:
    ans += l[1:len(l)].count('1') - 1

print(ans)