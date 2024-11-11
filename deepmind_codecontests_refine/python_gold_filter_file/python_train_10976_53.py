n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in range(n):
    if(l[i]+k<=5):
        c+=1
print(c//3)