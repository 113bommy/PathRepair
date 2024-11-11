n = input()
a = list(map(int, input().split()))
a.sort()
print(abs(sum(a[::2]) - sum(a[1::2])))