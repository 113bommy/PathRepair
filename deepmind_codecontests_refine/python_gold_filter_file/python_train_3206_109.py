a,b,k = map(int,input().split())
A = max(a-k,0)
B = max(b-max(k-a,0),0)
print(A,B)