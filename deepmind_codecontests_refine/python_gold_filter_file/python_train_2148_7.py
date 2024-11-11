n = int(input())
m = list(map(int, input().split(" ")))
c = set()
for i in m[::-1]:
    if i not in c:
        c.add(i)
        ans = i
        
print(ans)