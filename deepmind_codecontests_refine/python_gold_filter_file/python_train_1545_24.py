a = [input() for _ in range(int(input()))]
b = [input() for _ in range(int(input()))]
l = list(set(a))
c = max(0, max([a.count(i) - b.count(i) for i in l]))
print(c)