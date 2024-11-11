import sys

N = int(sys.stdin.readline().strip())

array = [None for _ in range(2**N)]
for i in range(int(2**N)):
    array[i] = int(sys.stdin.readline().strip())

for stage in range(N):
    for i in range(int(2**(N-stage-1))):
        tmp = abs(array[i*2] - array[i*2+1])
        array[i] = tmp if tmp != 0 else array[i*2]
        #print(array)

print(array[0])