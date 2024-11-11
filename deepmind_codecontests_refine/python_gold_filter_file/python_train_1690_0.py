n=int(input())
l=list(map(int,input().split()))
ls=[0]*1000000
for i in range(n):
    ls[l[i]-i]+=l[i]
print(max(ls))
        