def query(a):
    print('?', *a, flush=True)
    pos, val = map(int, input().split())
    return pos, val

def printAns(ans):
    print('! %d' % ans, flush=True)

n, k = map(int, input().split())
res = []
for i in range(1, k + 2):
    a = list(filter(lambda x: x != i, range(1, k + 2)))
    pos, val = query(a)
    res.append(val)
printAns(res.count(max(res)))
