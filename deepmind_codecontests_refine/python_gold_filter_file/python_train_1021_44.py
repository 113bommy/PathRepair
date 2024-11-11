H, W = map(int, input().split())
list=["."+input()+"." for i in range(H)]
list=["."*(W+2)]+list+["."*(W+2)]
a=0
for h in range(H):
    for w in range(W):
        if list[h][w] == "#":
            if list[h+1][w] == "." and list[h-1][w] == "." and list[h][w-1] == "." and list[h][w+1] == ".":
                a=1
print("Yes" if a==0 else "No")