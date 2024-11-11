s , a = list(map(int,input().split(" ")))
r = []
for i in range(s):
    q , s = map(int,input().split())
    r.append(q*(a/s))
print(min(r))