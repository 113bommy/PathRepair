n = int(input())
board = sorted(map(int,input().split()))
b = w = 0
for i in range(n//2):
    b += abs(board[-i-1] - (n-i*2))
    w += abs(board[-i-1] - (n-1-i*2))
print(min(b,w))