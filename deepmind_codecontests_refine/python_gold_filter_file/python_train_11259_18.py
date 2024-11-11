def ceil_div(a, b):
    r = a // b
    if a % b != 0:
        r += 1
    return r

def main():
    n, t = map(int, input().split(' '))
    
    ans = 0
    tt = 1000000000

    for i in range(n):
        s, d = map(int, input().split(' '))
        if s < t:
            s += d * ceil_div(t - s, d)

        if s < tt:
            tt = s
            ans = i + 1

    print(ans)

if __name__ == '__main__':
    main()

