N=int(input())
D,X=map(int,input().split())
a=0
for i in range(N):
    A=int(input())
    a+=1+((D-1)//A)
print(X+a)