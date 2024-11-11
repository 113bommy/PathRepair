n,A,B,C,T=map(int,input().split())
arr=map(int,input().split())
print(A*n+((C-B)*(n*T-sum(arr)) if B<C else 0))