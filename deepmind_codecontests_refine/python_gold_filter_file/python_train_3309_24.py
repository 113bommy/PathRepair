s,b = input().split()
d = {}
d[s],d[b] = [int(x) for x in input().split()]
d[input()] -= 1
print(d[s],d[b])