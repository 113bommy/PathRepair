n = int(input())
l = list(set(map(int,input().split())))
l.sort()
if len(l) == 1:
    print("NO")
else:
    print(l[1])