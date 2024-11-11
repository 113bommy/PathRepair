n = int(input())
a = sorted(list(map(int, input().split())))
print(sum(a[::-2])-sum(a[-2::-2]))