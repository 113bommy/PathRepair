n = int(input())
l = input()
r = []
for i in range(n):
    if (n+i)%2 == 1: r.append(l[i])
    else: r.insert(0, l[i])
print(''.join(r))
