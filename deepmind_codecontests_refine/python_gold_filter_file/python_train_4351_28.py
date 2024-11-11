x=list(map(int,input().split()))
y=list(map(int,input().split()))
z=list(map(int,input().split()))
A=[x,y,z]
X=[A[0][0],A[1][0],A[2][0]]
Y=[A[0][1],A[1][1],A[2][1]]
Z=[A[0][2],A[1][2],A[2][2]]
P=[A[0][0],A[1][1],A[2][2]]
Q=[A[0][2],A[1][1],A[2][0]]
B=[]
for i in range(int(input())):
    B.append(int(input()))
C=[x,y,z,X,Y,Z,P,Q]
for c in C:
    if set(c)<=set(B):
        print("Yes")
        break
else:
    print("No")