l = [int(x) for x in input().split()]
l.sort()
print(int(min(l[0]+l[1],sum(l)//3)))