n, x = list(map(int, input().split()))
a = list(map(int, input().split()))
prev = set()
done = set()
is_same = False
is_once = False
is_twice = False
for v in a:
    if v in prev:
        is_same = True
        break
    elif v in done or v & x in prev:
        is_once = True
    elif v & x in done:
        is_twice = True
    prev.add(v)
    if v & x != v:
        done.add(v & x)
if is_same:
    print(0)
elif is_once:
    print(1)
elif is_twice:
    print(2)
else:
    print(-1)