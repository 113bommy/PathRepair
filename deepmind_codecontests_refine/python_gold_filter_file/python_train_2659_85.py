n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in l:
    if(i>k):
        c+=2
    else:
        c+=1
print(c)
