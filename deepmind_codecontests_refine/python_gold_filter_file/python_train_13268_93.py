n=int(input())
count=0
for i in range(n):
    k,q=map(int,input().split())
    if q-k>=2:
        count+=1
print(count)
