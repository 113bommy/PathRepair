n = int(input())
s = map(int, input().split())
t =set(s)
#print(t)
t = list(t)
t.sort()
#print(t)
if len(t)>=2:
    print(t[1])
else:
    print("NO")