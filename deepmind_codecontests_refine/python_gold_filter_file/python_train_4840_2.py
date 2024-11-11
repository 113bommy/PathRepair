n = int(input())
a = [0]*n
ans = []
for i in range(n):
    cur = set(input().split())
    if not('3' in cur or '1' in cur):
        ans.append(i+1)
print (len (ans))
print (*ans)