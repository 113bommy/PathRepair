N = int(input())
a = list(map(int, input().split()))
a.sort()
print(abs(sum(a[0::2]) - sum(a[1::2])))