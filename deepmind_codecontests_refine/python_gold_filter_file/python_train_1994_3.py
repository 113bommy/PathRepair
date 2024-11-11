n = input()
a = [int(i) for i in input().split()]
m = ((max(a) - min(a)) / 2) + min(a)

j = 1
for i in a:
    if i != min(a) and i != max(a) and i != m:
       
        j = 0
        break

if j == 1:
    if int(m) == m:
        print(int(m) - min(a))
    else:
        print(max(a) - min(a))
else:
    print(-1)
        