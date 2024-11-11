A,B,K = map(int,input().split())
print(max(A-K,0),min(B,max(A+B-K,0)))