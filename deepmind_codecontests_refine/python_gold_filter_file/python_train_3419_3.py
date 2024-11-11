H, W, d = map(int, input().split())
C = ["R", "Y", "G", "B"]
if d%2==1:
    for i in range(H):
        out = ""
        for j in range(W):
            out += C[(i+j)%4]
        print(out)
elif d%4 == 2:
    for i in range(H):
        out = ""
        for j in range(W):
            out += C[i%2*2+(i//2+j//2)%2]
        print(out)
else:
    for i in range(H):
        out = ""
        for j in range(W):
            out += C[(i+j)//d%2*2+(i-j)//d%2]
        print(out)
