s=[input() for _ in range(int(input()))]
t=[input() for _ in range(int(input()))]
 
res=0
for i in set(s):
    res=max(s.count(i)-t.count(i),res)
print(res)