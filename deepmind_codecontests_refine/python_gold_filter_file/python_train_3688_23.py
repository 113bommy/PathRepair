n=int(input())
a=[*map(int,input().split())]
x,y=[*map(int,input().split())]
ans=y-x
sl=ans
count=0
for i in range(x-1,n+1):
    if sl==0:
        break
    else:
        count+=a[i]
        sl-=1
print(count)