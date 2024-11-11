h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]
r = "Yes"
for i in range(1, h-1):
    for j in range(1, w-1):
        if s[i][j] == "#" and s[i - 1][j] == "." and s[i + 1][j] == "." and s[i][j - 1] == "." and s[i][j + 1] == ".":
          r = "No"
print(r)

