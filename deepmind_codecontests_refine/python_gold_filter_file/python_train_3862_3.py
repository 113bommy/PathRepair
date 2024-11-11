n, q = map(int, input().split())
v = list(map(int, input().split()))
d = [list() for i in range(n)]
r = [1] * n
l = [0] * n
for j in range(n-1):
    d[v[j]-1].append(j+1)
def push():
    stack = list()
    re_stack = list()
    stack.append(0)
    while True:
        if len(stack) == 0:
            return re_stack
        tmp = stack.pop(0)
        re_stack.append(tmp)
        tmp_ = d[tmp]
        stack = tmp_ + stack
s = push()
for i in range(n):
    l[s[i]] = i
for i in range(n-1, -1, -1):
    for j in d[s[i]]:
        r[s[i]] += r[j]
ss=[]
for x in range(q):
    u, k = map(int, input().split())
    if k > r[u-1]:
        ss.append(-1)
    else:
        ss.append(s[l[u-1]+k-1]+1)
print('\n'.join(map(str, ss)))