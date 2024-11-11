n=int(input())
s=[input() for i in range(n)]
m=int(input())
t=[input() for i in range(m)]
a=[0]
for i in set(s):
    a.append((s.count(i)-t.count(i)))
print(max(a))