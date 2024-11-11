n=int(input())
x=sorted(map(int,input().split()))
minv=maxv=-2
mn=mx=0
for val in x:
    if(minv<val-1):
        minv=val+1
        mn+=1
    if(maxv<val+1):
        maxv=max(maxv+1,val-1)
        mx+=1
print(mn,mx)