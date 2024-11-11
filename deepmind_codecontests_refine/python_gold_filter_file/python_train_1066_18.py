import sys
input = sys.stdin.readline

'''

'''

def solve(n, x, m, edges):
    low, high = None, None
    for l, r in edges:
        if l <= x <= r:
            if low == None and high == None:
                low = l
                high = r
            else:
                low = min(low, l)
                high = max(high, r)
        else:
            if (low != None and high != None) and (l <= low <= r or l <= high <= r):
                low = min(low, l)
                high = max(high, r)
        #print(low, high)
    
    if low == high == None:
        return 1
    else:
        return (high-low)+1
    

t = int(input())
for _ in range(t):
    n, x, m = map(int, input().split())
    edges = []
    for _ in range(m):
        l, r = map(int, input().split())
        edges.append((l, r))
    print(solve(n, x, m, edges))