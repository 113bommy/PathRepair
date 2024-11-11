n=int(input())
l=[int(x) for x in input().split(' ')]
d=[l.count(i) for i in set(l)]
print(n-max(d))