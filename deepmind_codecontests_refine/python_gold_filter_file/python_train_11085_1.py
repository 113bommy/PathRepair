n = int(input())
a = list(map(int, input().split()))

one = n-a.count(1)
two = n-a.count(2)
th = n-a.count(3)

print(min(one, two, th))
