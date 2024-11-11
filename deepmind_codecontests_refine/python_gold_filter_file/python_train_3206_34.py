A,B,K = map(int,input().split())
x = A-K
B = min(max(B+x,0),B)
A = max(x,0)
print(A,B)