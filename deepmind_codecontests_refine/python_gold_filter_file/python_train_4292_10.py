from math import sqrt, floor

t = int(input())
for _ in range(t):
    n = int(input())
    if n < 24:
        print("NO")
    else:
        m = floor(sqrt(n)) + 1
        d = 0
        divs = []
        for i in range(2, m):
            if n % i == 0:
                d += 1
                divs.append(i)
                n //= i
                break
        if d == 0:
            print("NO")
        else:
            m = floor(sqrt(n)) + 1
            for i in range(divs[0]+1, m):
                if n % i == 0:
                    d += 1
                    divs.append(i)
                    n //= i
                    break
            if d == 2:
                if n in divs:
                    print("NO")
                else:
                    divs.append(n)
                    ans = map(str, divs)
                    print("YES")
                    print(' '.join(ans))
            else:
                print("NO")