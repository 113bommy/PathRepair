N = int(input())
L = input()
A = []
Tel = ''
for k in L:
    A.append(int(k))
m = 0
if N%2==0:
    Tel = str(A[0])+str(A[1])+'-'
    for k in range (2,len(A)-1,2):
        Tel += str(A[k])+str(A[k+1])+'-'
else:
    Tel = str(A[0])+str(A[1])+str(A[2])+'-'
    for k in range (3,len(A)-1,2):
        Tel += str(A[k])+str(A[k+1])+'-'
R = ''
for t in range (len(Tel)-1):
    R += Tel[t]
print(R)