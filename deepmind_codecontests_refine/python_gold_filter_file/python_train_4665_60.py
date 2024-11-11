n=int(input())
d=[int(a) for a in input().split()]

d.sort()

print(d[n//2]-d[n//2-1])