def inp_n():
    return int(input())

def inp_list():
    return list(map(int, input().split()))

def inp_mul_num():
    return map(int, input().split())

def is_odd(n):
    if n & 1:
        return True
    return False


for _ in range(inp_n()):
    n = inp_n()
    v = input()
    if len(v) == 2:
        if v[0] >= v[1]:
            print('NO')
        else:
            print('YES')
            print(2)
            print(v[0], v[1])
    else:
        print('YES')
        print(2)
        print(v[0], v[1:])
