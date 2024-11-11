N,A,B=map(int, input().split())
len=A+B
print((N // len)* A + min(A, N % len))
