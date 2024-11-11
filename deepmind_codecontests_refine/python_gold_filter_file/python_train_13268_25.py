n=int(input())
count=0
for i in range(n):
    a,b=map(int,input().split())
    if abs(a-b)>=2:
        count+=1
print(count)