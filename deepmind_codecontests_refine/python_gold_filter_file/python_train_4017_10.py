a = input()
b = input()

if a == b:
    print('-1')
#elif a in b:
 #   print(max(map(len, b.split(a))))
#elif b in a:
 #   print(max(map(len, a.split(b))))
else:
    print(max(len(a), len(b)))
