n = int(input())
c = list(map(lambda x: (int(x[1]),-x[0]),enumerate(input().split())))
so = sorted(c)
for i in range(int(input())):
    k,r = map(int,input().split())
    now = so[-k:]
    now.sort(key = lambda x: -x[1])
    print(now[r-1][0])