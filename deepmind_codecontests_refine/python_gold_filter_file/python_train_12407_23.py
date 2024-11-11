a = int(input())
b = input()
A = []
k = 0
for i in range(a):
    q,w = map(int,input().split())
    A.append([int(b[i]),q,w])
    k+=int(b[i])
for i in range(1000):
    V = 0
    for j in range(len(A)):
        if i>=A[j][2]:
            if ((i-A[j][2])//A[j][1])%2 == 0:
                V+=A[j][0]*(-1)+1
            else: V+=A[j][0]
        else:
            V+=A[j][0]
    if V>k:
        k=V
print(k)