A,B=map(int,input().split())

X=A%B
print(min(X,B-X))