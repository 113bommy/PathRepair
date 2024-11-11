n,s=map(int,input().split())
A=list(map(int,input().split()))
if (sum(A)-max(A))<=s:
    print("YES")
else:
    print("NO")