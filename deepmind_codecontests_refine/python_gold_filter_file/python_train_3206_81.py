a,b,k = map(int, input().split())
print(max(a-k,0),max(b+min(a-k,0),0))