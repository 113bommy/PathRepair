h, w = map(int, input().split())
s = [input() for _ in range(h)]

for i in range(1,h-1):
    for j in range(1,w-1):
        if(s[i][j] == "#"):
            if(s[i - 1][j] == "." and s[i + 1][j] == "." and s[i][j - 1] == "." and s[i][j + 1] == "."):
                print("No")
                # print("[%d][%d]"%(i,j))
                exit()
print("Yes")