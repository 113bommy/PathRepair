n,k=map(int,input().split())
arr=list(map(int,input().split()))
a=0
for i in arr:
    if i+k<=5:
        a=a+1
print(a//3)