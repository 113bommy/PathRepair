import sys
 
# inf = open('input.txt', 'r')
# reader = (line.rstrip() for line in inf)
reader = (line.rstrip() for line in sys.stdin)
input = reader.__next__
 
 
n, m, k = map(int, input().split())
 
def route(n, m, k):
    limit = 4 * n * m - 2 * n - 2 * m
    # print(limit)
    if k > limit:
        return None
    if m == 1:
        if k > n - 1:
            ans = [(n - 1, 'D'), (k - (n - 1), 'U')]
        else:
            ans = [(k, 'D')]
        return ans
    
    fullR = (m - 1, 'R')
    fullL = (m - 1, 'L')
    D = (1, 'D')
    G = 'RUD'    
    
    ans = []
    
    if k > m - 1:
        ans.append(fullR)
        k -= m - 1
    else:
        ans.append((k, 'R'))
        return ans
    
    if k > m - 1:
        ans.append(fullL)
        k -= m - 1
    else:
        ans.append((k, 'L'))
        return ans
        
    r = 1
    while k > 0 and r < n:
        ans.append(D)
        r += 1
        k -= 1
    
        t = 0
        while k >= 3 and t < m - 1:
            t += 1
            k -= 3
        
        if t > 0:
            ans.append((t, G))
        
        if k == 0:
            break
        
        if t == m - 1:
            if k > m - 1:
                ans.append(fullL)
                k -= m - 1
            else:
                ans.append((k, 'L'))
                k = 0
                break
        else:
            ans.append((1, G[:k]))
            k = 0
            break
    if k > 0:
        ans.append((k, 'U'))
    return ans
 
ans = route(n, m, k)
if ans is None:
    print('NO')
else:
    print('YES')
    print(len(ans))
    for t, s in ans:
        sys.stdout.write(f'{t} {s}\n')
 
# inf.close()