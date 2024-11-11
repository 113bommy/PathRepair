N,M = map(int,input().split())
ans = ((N-M)*100+1900*M)*2**M
print(ans)