n=int(input())
T,X,Y=0,0,0

a='Yes'
for i in range(n):
    t,x,y=map(int,input().split())
    if abs(x-X)+abs(y-Y)>t-T or t%2!=(x+y)%2:
        a='No'
        break
    T,X,Y=t,x,y
print(a)