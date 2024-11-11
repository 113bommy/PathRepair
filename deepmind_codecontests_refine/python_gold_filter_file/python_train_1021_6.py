h, w = map(int, input().split())
S = [list(input()) for _ in range(h)]
drc = [[0,1],[0,-1],[1,0],[-1,0]]
for i in range(h):
  for j in range(w):
    if S[i][j] == "#":
      if all([S[i+y][j+x] == "." for x, y in drc if (0 <= j+x < w) and (0 <= i+y < h)]):
        print("No")
        exit()
print("Yes")