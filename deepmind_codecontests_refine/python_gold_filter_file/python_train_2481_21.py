n, d, x ,*aa = map(int, open(0).read().split())

print(n+sum((d-1)//a for a in aa)+x)