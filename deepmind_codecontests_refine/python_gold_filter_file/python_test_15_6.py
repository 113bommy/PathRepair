import sys
from collections import deque
# sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
 
 
T = int(input())
while T:
    T -= 1
    n, m, k = map(int, input().split())
    field = [list(input()) for _ in range(n)]
    ch = [[0 for _ in range(m)] for _ in range(n)]
    queue = deque()
    for i in range(n):
        for j in range(m):
            if field[i][j] == '*':
                queue.append([i, j])
    
    while queue:
        x, y = queue.popleft()
        h = 0
        while True:
            if 0 <= x-h and 0 <= y-h and y+h < m and field[x-h][y-h] == '*' and field[x-h][y+h] == '*':
                h += 1
            else:
                h -= 1
                break
        if h >= k:
            for i in range(h+1):
                ch[x-i][y-i] = 1
                ch[x-i][y+i] = 1
    flag = 0
    for i in range(n):
        for j in range(m):
            if field[i][j] == '*' and not ch[i][j]:
                print('NO')
                flag = 1
                break
        if flag:
            break
    if not flag:
        print('YES')