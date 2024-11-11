H,W=map(int,input().split())
S=[input()+'.'for _ in range(H)]+['.'*(W+2)]
print(('Yes','No')[any(S[y-1][x]==S[y+1][x]==S[y][x-1]==S[y][x+1]=='.'for y in range(H)for x in range(W)if S[y][x]=='#')])