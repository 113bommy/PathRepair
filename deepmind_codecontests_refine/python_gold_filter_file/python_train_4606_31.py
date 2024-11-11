n = int(input())
l = [5,0,2,3,1,4]
l.reverse()
res = 0
for i in l:
    res += (n%2) * (2 ** i)
    n //= 2
print(res)