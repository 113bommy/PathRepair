n,m = map(int, input().split())
mini = min(n,m)
lt = [(i,mini-i) for i in range(mini+1)]
print(len(lt))
for p in lt:
    print(*p)