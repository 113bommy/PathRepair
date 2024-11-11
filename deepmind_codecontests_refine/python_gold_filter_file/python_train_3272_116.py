n = input()
col = input().split()
n = int(n)
i = 0
while i<len(col):
     col[i] = int(col[i])
     i +=1
col.sort()

print(*col)
