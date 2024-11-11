H, W = map(int, input().split())
S = [input() for i in range(H)]

for i in range(H):
  for j in range(W):
    if S[i][j] == "#":
      bk = sum([t[j].count("#") for t in S[max(0,i-1):min(H,i+2)]])
      bk += S[i][max(0,j-1):min(W,j+2)].count("#")-1
      if bk == 1:
        print("No")
        exit()

print("Yes")
