n = int(input())
a = input()
A = []
for i in a.split():
    A.append(int(i))
Max = 0
b = 0
c = 0

for j in range(0,n-1):
    if A[j+1]-A[j]>Max:
        Max = A[j+1] - A[j]
        b = j 
B=[]
for k in range(0,n-2):
    if A[k+2]-A[k]<=Max:
        c = 1
        break
    if A[k+2]-A[k]>Max:
        B.append(A[k+2]-A[k])
if c == 1:
    print(Max)
elif c == 0:
    print(min(B))
