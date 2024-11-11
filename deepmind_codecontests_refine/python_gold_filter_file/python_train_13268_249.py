t=int(input())
count=0
for i in range(t):
    n,k=map(int,input().split())
    if (k-n)>=2:
        count+=1
print(count)
