n, v = map(int, input().split())
sel = []
for j in range(n):
    no, *item = map(int, input().split())
    for i in item:
        if i < v:
            sel.append(j+1)
            break
print(len(sel))
print(*sorted(sel), sep=" ")
