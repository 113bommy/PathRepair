import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))

print(n)
print(1,n,500000)
for k in range(1,n):
    print(2,k,(A[k-1]+500000)-k+1)
