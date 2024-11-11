s = [input() for _ in range(int(input()))]
t = [input() for _ in range(int(input()))]

l = list(set(s))

print(max(0, max(s.count(l[i]) - t.count(l[i]) for i in range(len(l)))))
