from sys import stdin as fin
# fin = open("cfr375a.in")

# n = int(fin.readline())
a, b, c = sorted(map(int, fin.readline().split()))
# line = tuple(fin.readline().strip())
print(c - a)