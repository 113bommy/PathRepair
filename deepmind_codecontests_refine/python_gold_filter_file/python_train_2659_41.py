x,y=map(int,input().split())
l=list(map(int,input().split()))
s=0
for i in l:
    if i <=y:
        s+=1
    else:
        s+=2
print(s)