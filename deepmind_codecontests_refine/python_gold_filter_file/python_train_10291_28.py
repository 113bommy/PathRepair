S = 'ACABABAABABA'
x,y = map(int, input().split())
print('Yes' if S[x-1]==S[y-1] else 'No')