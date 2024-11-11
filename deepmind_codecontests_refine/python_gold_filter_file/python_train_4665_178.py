n=int(input())
d=[int(x) for x in input().split()]
d.sort()
print(d[n//2]-d[n//2-1])