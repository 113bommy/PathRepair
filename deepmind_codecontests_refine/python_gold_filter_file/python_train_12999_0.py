import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,*A = map(int,read().split())

A.sort(reverse = True)

A.append(0)
i = 0
while A[i + 1] > i + 1:
    i += 1

x = A[i] - (i + 1)
y = max(j for j in range(N) if A[j] > i) - i

answer = 'First' if x&1 or y&1 else 'Second'
print(answer)