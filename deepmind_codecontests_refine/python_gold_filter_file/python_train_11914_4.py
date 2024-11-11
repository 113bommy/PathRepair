# cook your dish here
n,a,b=list(map(int,input().split()))
A=list(map(int,input().split()))
B=list(map(int,input().split()))
arr=[1]*(n+1)
for i in B:
    if i not in A:
        arr[i]=2
print(*arr[1:])