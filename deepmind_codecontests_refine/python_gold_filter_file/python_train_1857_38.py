input()
a = list(map(int, input().split()))
a.sort(reverse=1)
print(sum(a[::2]) - sum(a[1::2]))