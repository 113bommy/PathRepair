x=int(input())
n=x//100

if 0<=x%100<=5*n:
    print(1)
else:
    print(0)
