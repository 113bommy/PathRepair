n=int(input())
l=list(map(int,input().split()))
r=[]
ls=[0]*2000000
for i in range(n):
    ls[l[i]-i]+=l[i]
print(max(ls))
        
    