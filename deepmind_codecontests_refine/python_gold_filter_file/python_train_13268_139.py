n = int(input())
count = 0
for N in range(n):
    p,q = list(map(int,input().split()))
    if(q-p>=2):
        count+=1
print(count)