N,A,B = map(int,input().split())
p = N//(A+B)
q = N%(A+B)
print(A*p+min(q,A))