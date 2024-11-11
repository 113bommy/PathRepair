s = input()

a = s.count('o')
b = s.count('-')

if a != 0:
    x = b / a

    if x - int(x) > 0:
        print("NO")
    else:
        print("YES")
else:
    print("YES")
