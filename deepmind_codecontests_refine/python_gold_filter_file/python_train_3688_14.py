n=input()
A=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(A[a-1:b-1]))