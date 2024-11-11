import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
white = 0
black = 0
for i, a in enumerate(A):
    if a%2 == 0:
        white += a//2
        black += a//2
    else:
        if i%2 == 0:
            black += a//2
            white += a//2+1
        else:
            white += a//2
            black += a//2+1

print(min(black, white))