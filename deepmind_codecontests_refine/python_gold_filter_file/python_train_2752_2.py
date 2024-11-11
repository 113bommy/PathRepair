n=int(input())
l=list(map(int,input().split()))
x=0
cnt=0
for i in l:
    if i==-1:
        if x==0:
            cnt+=1
        else:
            x-=1
    elif i!=-1:
        x+=i
print(cnt)