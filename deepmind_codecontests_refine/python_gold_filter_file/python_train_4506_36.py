t=int(input())
for i in range(t):
    l=[int (x) for x in input().split(" ")]
    l.sort()
    print(l[-1]+l[-2]-1)