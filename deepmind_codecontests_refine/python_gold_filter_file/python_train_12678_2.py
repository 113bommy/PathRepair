N,A,B = map(int,input().split())
x = N//(A+B)
y = N%(A+B)
print(A*x+min(A,y))
