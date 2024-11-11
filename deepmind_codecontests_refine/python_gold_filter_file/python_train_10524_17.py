x=int(input())
sum1=1
m = sum(map(int, input().split()))
for i in range(x-1):
    n = sum(map(int, input().split()))
    if n>m:
        sum1+=1
print(sum1)