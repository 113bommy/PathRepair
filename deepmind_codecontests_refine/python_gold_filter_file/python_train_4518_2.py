A,B,n=map(int,input().split())
X=1001

for i in range(-1000,1001):
    if A*(i**n) == B :
        X=i
        break;


if X!=1001 :
    print(X)
else :
    print("No solution")