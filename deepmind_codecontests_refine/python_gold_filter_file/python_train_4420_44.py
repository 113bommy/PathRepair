n = input()
a = n
if len(a)==2:
    print(0)
else:
    a = set(map(str, n[1:-1:].split(", ")))
    print(len(a))
