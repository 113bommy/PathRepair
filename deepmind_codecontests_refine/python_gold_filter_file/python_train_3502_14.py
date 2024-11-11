n, m = [int(v) for v in input().split()]

ip2name = {}
for _ in range(n):
    name, ip = input().split()
    ip2name[ip] = name

for _ in range(m):
    cmd, ip = input().split()
    assert ip[-1] == ';'
    ip = ip[:-1]
    print('%s %s; #%s' % (cmd, ip, ip2name[ip]))
