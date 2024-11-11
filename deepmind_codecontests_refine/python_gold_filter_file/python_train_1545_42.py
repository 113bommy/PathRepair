l=[input() for _ in range(int(input()))]
m=[input() for _ in range(int(input()))]
n=set(l)
h=max([l.count(i)-m.count(i) for i in n])
print(max(0,h))