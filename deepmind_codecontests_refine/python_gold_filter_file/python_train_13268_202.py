n=int(input())
count=0
for i in range(n):
    b=list(map(int,input().split()))
    if b[1]-b[0]>=2:
        count+=1
print(count)
