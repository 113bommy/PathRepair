n,h=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in l:
    if i>h:
        c+=2
    else:
        c+=1
print(c)
