m,h=map(int,input().split())
l=list(map(int,input().split()))
s=0
for i in l:
    if i<=h:
        s+=1
    else:
        s+=2
print(s)