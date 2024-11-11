def max_sum(x):
    return x**2
def ans(x):
    res = 1
    while max_sum(res) < x:
        res += 1
    return res

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print(ans(int(input())))