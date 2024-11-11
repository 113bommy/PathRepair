import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


H, W, h, w = map(int, input().split())
v = [[0]*W for _ in range(H)]
if H%h==0 and W%w==0:
    print("No")
else:
    for i in range(H//h):
        for j in range(W//w):
            v[(i+1)*h-1][(j+1)*w-1] = -10**9
    for i in range(H//h+1):
        for j in range(W//w+1):
            if i*h<H and j*w<W:
                v[(i)*h][(j)*w] = 10**9-1
    ss = sum(sum(vv) for vv in v)
    if ss>0:
        print("Yes")
        write("\n".join(" ".join(map(str, vv)) for vv in v))
    else:
        print("No")