##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

ns = input()
l = len(ns)
n = int(ns[0:l-1])
s = ns[l-1]

k = (n-1)//4
res = k*(6+1+6+3)

r = (n-1)%4
if r == 1 or r == 3:
    res += 6+1

if s == 'f':
    res += 1
elif s == 'e':
    res += 2
elif s == 'd':
    res += 3
elif s == 'a':
    res += 4
elif s == 'b':
    res += 5
elif s == 'c':
    res += 6

print(res)