import math
L = int(input())
N = math.floor(math.log2(L))+1

M = N*2-2
add_path = []
for i in range(1,N)[::-1]:
    if L-2**(i-1) >= 2**(N-1):
        add_path.append([i, L-2**(i-1)]); L -= 2**(i-1)
print(N, M+len(add_path))
for i in range(1,N):
    print(i, i+1, 0)
    print(i, i+1, 2**(i-1))
for i in add_path:
    print(i[0], N, i[1])