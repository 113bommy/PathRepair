A,B,C = map(int,input().split())
for i in range(B):
  if (i+1)*A%B== C:
    print('YES')
    exit()
print('NO')