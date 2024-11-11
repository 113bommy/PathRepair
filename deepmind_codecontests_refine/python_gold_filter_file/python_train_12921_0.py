n, a, b = int(input()), list(map(int, input().split())), list(map(int, input().split()))
pos = [0]*(n+5)
for i in range(n):
    pos[a[i]] = i+1
cur_pos = 0
for i in range(n):
    if pos[b[i]] < cur_pos:
        print(0)
    else:
        print(pos[b[i]]-cur_pos)
        cur_pos = pos[b[i]]
