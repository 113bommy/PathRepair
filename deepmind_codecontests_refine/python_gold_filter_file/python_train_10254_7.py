def smallest(x):
    if len(x) % 2:
        return x
    s1 = smallest(x[:len(x)//2])
    s2 = smallest(x[len(x)//2:])
    if s1 < s2:
        return s1 + s2
    else:
        return s2 + s1

def are_equiv(x, y):
    if smallest(x) == smallest(y):
        print("YES")
    else:
        print("NO")

s1 = input()
s2 = input()

are_equiv(s1, s2)
