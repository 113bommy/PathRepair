n,h=map(int,input().split())
l=list(map(int,input().split()))
m=0
for i in l:
    if i>h:
        m+=2
    else:
        m+=1
print(m)