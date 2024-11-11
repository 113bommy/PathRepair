n = int(input())
res = n
for i in range(n+1):
    cc=0
    t=i
    while(t>0):
        cc+=t%6
        t = int(t/6)
    t = n-i
    while(t>0):
        cc+=t%9
        t = int(t/9)
    if res > cc:
        res =cc
print(res)
