#22:21
#解説解答
t = int(input())
scale = 64
#scale = 4
double = [2**d for d in range(scale)]
double.reverse()
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    s = input()
    base = [0 for _ in range(scale)]
    for i in range(n)[::-1]:
        now = a[i]
        for d in range(scale):
            if now & double[d]:
                if base[d]:
                    now ^= base[d]
                else:
                    base[d] = now
                    break
        else:
            continue
        if s[i] == '1':
            print(1)
            break
    else:
        print(0)