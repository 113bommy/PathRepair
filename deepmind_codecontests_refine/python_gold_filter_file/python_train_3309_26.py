S,T=input().split()
A,B=map(int,input().split())
U=input()

if S==U:
    A=A-1
else:
    B=B-1
print(A,B)