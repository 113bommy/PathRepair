
#sol 1---------------------------------------------------
'''
n = int(input())
V = list(map(int, input().split()))

A = set()
B = set()

T = n-1
for i in range(-1,n):
    if i >= 0:
        if V[i] in A:
            break

        A.add(V[i])

    B.clear()
    for j in range(n-1, -1, -1):
        if V[j] in B or V[j] in A:
            break

        B.add(V[j])

    T = min(T,j-i)

print(T)
'''

n = int(input())
V = list(map(int, input().split()))

rightmost = {}
leftmost = {}

R = set()
j = 0
for i in range(n-1, -1, -1):
    if V[i] in R:
        j = i
        break

    R.add(V[i])
    rightmost[V[i]] = i

T = j+1
R.clear()
for i in range(n):
    if V[i] in R:
        break
    R.add(V[i])

    if V[i] in rightmost:
        j = max(j, rightmost[V[i]])
   
    T = min(T, j-i)

print(T)

