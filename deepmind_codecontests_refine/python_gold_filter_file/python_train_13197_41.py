n = int(input())
a = list(map(int, input().split()))
a *= 2
a.sort(reverse=True)
print(sum(a[1:n]))