n,m=map(int,input().split())
l=list(map(int,input().split()))
s=0
for i in l:
    if(i>m):
        s+=2
    else:
        s+=1
print(s)