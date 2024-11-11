ls = [int(i) for i in input().split()]

val = sum(ls)

initial = val//len(ls)
if val==0:
    print("-1")
elif initial*len(ls)==val:
    print(initial)
else:
    print("-1")