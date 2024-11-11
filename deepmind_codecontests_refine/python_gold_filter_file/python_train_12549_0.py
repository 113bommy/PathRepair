n = int(input())
a = list(input())
count = 0
for i in a:
    if i == ' ':
        a.remove(i)

if len(a) == 1:
    if a[0] == '0':
        print("NO")
    else:
        print("YES")
else:
    for i in a:
        if i == '0':
            count += 1

    if count == 1:
        print("YES")
    else:
        print("NO")
