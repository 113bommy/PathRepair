import sys
input = lambda: sys.stdin.readline().rstrip()
n, q = map(int, input().split())
move = []
for _ in range(q):
    r, c = map(int, input().split())
    move.append((r-1, c-1))
pos = [[0]*n for _ in range(2)]
r1 = [0]*n
cnt = 0
for r, c in move:
    pos[r][c] = 1-pos[r][c]
    if r==0:
        if pos[0][c]:
            if r1[c]:
                continue
            for i in range(max(0, c-1), min(n, c+2)):
                if pos[1][i]:
                    cnt += 1
                    r1[c] = 1
                    break
        else:
            if r1[c]==1:
                cnt -= 1
                r1[c] = 0
    else:
        if pos[r][c]:
            for i in range(max(0, c-1), min(n, c+2)):
                if r1[i]:
                    continue
                if pos[1-r][i]:
                    cnt += 1
                    r1[i] = 1
        else:
            for i in range(max(0, c-1), min(n, c+2)):
                if r1[i]==0:
                    continue
                for j in range(max(0, i-1), min(n, i+2)):
                    if pos[1][j]:
                        break
                else:
                    cnt -= 1
                    r1[i] = 0
    if cnt:
        print('No')
    else:
        print('Yes')