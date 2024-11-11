n = int(input())
a = sorted(list(map(int, input().split())))[::-1]
print(sum(a[0::2])-sum(a[1::2]))