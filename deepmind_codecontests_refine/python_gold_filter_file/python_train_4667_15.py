H,W=map(int,input().split())
M=[list(input()) for i in range(H)]
for i in range(H):
    if '#'in M[i]:
        s=[]
        for x in range(W):
            t=[M[y][x] for y in range(H)]
            if '#'in t: s.append(M[i][x])
        print(''.join(s))