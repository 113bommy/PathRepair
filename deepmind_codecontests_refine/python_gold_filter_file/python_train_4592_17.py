import math

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())

    if abs(a - b) != 1:
        print("NO")
        continue

    check = a + b

    is_prime = True

    if check % 2 == 0:
        is_prime = False
    else:
        for i in range(3, int(math.sqrt(check)) + 1, 2):
            if check % i == 0:
                is_prime = False
                break

    print("YES" if is_prime else "NO")