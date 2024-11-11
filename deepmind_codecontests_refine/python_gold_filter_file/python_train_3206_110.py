a, b, k = map(int, input().split())
 
if a<=k:
    print(0,max(b-k+a,0))
else:
    print(a-k,b)