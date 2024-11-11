N = int(input())
P = list(map(int,input().split()))

A = [i*(10**4*2+1)+1 for i in range(N)]
B = list(reversed(A))
for i in range(N):
    B[P[i]-1] += i

for i in A:
    print(i,end = " ")
print()
for i in B:
    print(i,end = " ")
