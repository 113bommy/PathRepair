a,b=map(int,input().split())
k,k1,k2,k3,k4,k5=0,0,0,0,0,0
for i in range(a):
    l=list(input().split())
    k=k+l.count('C')
    k1=k1+l.count('M')
    k2=k2+l.count('Y')
    k3=k3+l.count('W')
    k4=k4+l.count('G')
    k5=k5+l.count('B')
if k+k1+k2==0:
    print('#Black&White')
elif k+k1+k2>=1: 
    print('#Color')

