# b cannot lie on the simple path between node a and node c

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    fanout_root=None
    s=set()
    for _ in range(m):
        a, b, c = map(int, input().split())
        s.add(b)
    
    if 1 in s and 2 not in s:
        fanout_root=2
    else:
        for num in s:
            if num == 1: continue
            if num-1 not in s:
                fanout_root=num-1
                break
            elif num < n and num+1 not in s:
                fanout_root=num+1
                break
    for i in range(1,n+1):
        if i != fanout_root:
            print(f"{fanout_root} {i}")