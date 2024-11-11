a,b,k = map(int,input().split())

print(max(0,a-k), max(b+min(a-k,0), 0))
