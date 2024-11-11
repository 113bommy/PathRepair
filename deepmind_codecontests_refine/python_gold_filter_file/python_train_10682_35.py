n,k,t = map(int, input().split())
 
print(min(n,t) - max(0, t-k) )