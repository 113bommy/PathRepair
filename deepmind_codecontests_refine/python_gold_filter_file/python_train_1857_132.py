n = int(input())
a = sorted(list(map(int,input().split())))
print(abs(sum(a[::2])-sum(a[1::2])))