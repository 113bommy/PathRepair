n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in l:
    if(5-i>=k):
        c+=1
print(c//3)
