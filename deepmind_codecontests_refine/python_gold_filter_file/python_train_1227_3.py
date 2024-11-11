import math
N,L=map(int,input().split())
T=[int(input()) for i in range(N)]
X=0
Y=0
for i in range(N):
    for j in range(i+1,N):
        angle=math.pi*(T[j]+T[i])/L
        #print(math.cos(angle),math.sin(angle))
        X+=math.cos(angle)*(N-2-(j-i-1)*2)
        Y+=math.sin(angle)*(N-2-(j-i-1)*2)
A=(N*(N-1)*(N-2))//6
print(X/A,Y/A)
