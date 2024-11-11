import sys

input = sys.stdin.readline
print = sys.stdout.write

N,M,L = map(int,input().split())

A = [int(i) for i in input().split()]

components = 0
run = False
for i in A:
    if not run and i > L:
        run = True
        components += 1
    elif i <= L:
        run = False

for i in range(M):
    line = [int(j) for j in input().split()]
    if line[0] == 0:
        print(str(components) + "\n")
    else:
        q = line[1]
        r = line[2]
        A[q-1] += r
        if A[q-1] - r <= L and A[q-1] > L:
            if q > 1 and q < N:
                if A[q-2] <= L and A[q] <= L:
                    components += 1
                elif A[q-2] > L and A[q] > L:
                    components -= 1
            elif (q == 1 and N == 1) or (q == 1 and N > 1 and A[q] <= L) or (q == N and A[q-2] <= L):
                components += 1
            
        