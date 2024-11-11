l = list(map( int, input().split()))

n = l[0]
p = l[1]
k = l[2]
s=''

if p-k  > 1:
    s += '<< '
s += ''.join(map(lambda x: str(x) + ' ' if 0 < x <= n else '', range(p-k, p)))
s += '('+ str(p) +') '
s += ''.join(map(lambda x: str(x) + ' ' if 0 < x <= n else '', range(p+1, p+k+1)))

if p+k < n :
    s += '>>'
print(s)


