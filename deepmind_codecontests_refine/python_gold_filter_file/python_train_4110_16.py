m = "hello"


def score(a, b, c, d):
    ms = max((3*a)/10, a-(a/250)*c)
    vs = max((3*b)/10, b-(b/250)*d)
    if ms == vs:
        return "Tie"
    elif ms > vs:
        return "Misha"
    else:
        return "Vasya"


a, b, c, d = [int(x) for x in input("").split()]
print(score(a, b, c, d))
