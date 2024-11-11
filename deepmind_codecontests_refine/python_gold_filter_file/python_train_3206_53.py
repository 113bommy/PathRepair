A,B,K=map(int, input().split())
print(max(A-K,0),max(B+min(A-K,0),0))