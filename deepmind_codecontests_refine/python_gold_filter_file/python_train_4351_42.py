A = []
for i in range(3):
    p,q,r = map(int, input().split())
    A.append(p)
    A.append(q)
    A.append(r)
n = int(input())
for i in range(n):
    b = int(input())
    if b in A:
        A[A.index(b)] = 0

if A[0]==A[1]==A[2]==0 or A[3]==A[4]==A[5]==0 or A[6]==A[7]==A[8]==0 or A[0]==A[3]==A[6]==0 or A[1]==A[4]==A[7]==0 or A[2]==A[5]==A[8]==0 or A[0]==A[4]==A[8]==0 or A[2]==A[4]==A[6]==0:
    print("Yes")
else:
    print("No")
