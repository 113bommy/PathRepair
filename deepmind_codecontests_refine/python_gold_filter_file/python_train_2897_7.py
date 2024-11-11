# 解説AC
n = int(input())
board = [input() for i in range(n)]

def check(a, b):
    for i in range(n):
        for j in range(n):
            if board[(i-a)%n][(j-b)%n] != board[(j-a)%n][(i-b)%n]:
                return False
    return True

ans = 0
for i in range(n):
    if check(i,0):
        ans += n-i
    if check(0,i) and i >0:
        ans += n-i
print(ans)