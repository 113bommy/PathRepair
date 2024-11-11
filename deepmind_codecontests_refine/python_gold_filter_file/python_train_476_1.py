def get_test(input):
    return map(lambda x: int(x), input.split())
def solve(s, v1, v2, t1, t2):
    dt = 2*t1+s*v1-(2*t2+s*v2)
    if dt<0:
        return "First"
    elif dt>0:
        return "Second"
    return "Friendship"
print(solve(*get_test(input())))