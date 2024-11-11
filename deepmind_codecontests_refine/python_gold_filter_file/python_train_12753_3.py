from sys import stdin

l = int(stdin.readline())
p = int(stdin.readline())
q = int(stdin.readline())

print("%f" % ((l / (p + q)) * p))