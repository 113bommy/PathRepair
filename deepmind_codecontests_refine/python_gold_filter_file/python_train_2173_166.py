n,l = map(int, input().split())
l = [input() for i in range(n)]
l.sort()
print(''.join(l))