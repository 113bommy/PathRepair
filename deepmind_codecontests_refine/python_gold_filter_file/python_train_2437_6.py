n=int(input())
l=sorted([int(x) for x in input().split()])
print(l[-1], *l[1:-1:], l[0])
