x = input()
inp  = input().split(" ")
if len(inp)==3:
    print(int(inp[2])-int(inp[0]))
else:
    res = []
    for i in range(1, len(inp)-1):
        ans = -1
        for j in range(1, len(inp)):
            if i==j:
                ans = max(ans, int(inp[j+1])-int(inp[j-1]))
            else:
                ans = max(ans, int(inp[j])-int(inp[j-1]))
        res.append(ans)
    print(min(res))
