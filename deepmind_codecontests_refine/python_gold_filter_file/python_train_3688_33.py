a=int(input())
b=list(map(int,input().split()))
k,f=map(int,input().split())
sum=0
for i in range(k,f):
    sum+=b[i-1]
print(sum)