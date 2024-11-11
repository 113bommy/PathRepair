A,B,N = map(int,input().split())

n = min(B-1,N)

ans = (A*n)//B
print(ans)