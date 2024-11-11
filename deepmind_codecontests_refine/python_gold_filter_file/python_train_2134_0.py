a1, b1 = list(map(int, input().split()))
a2, b2 = list(map(int, input().split()))
a3, b3 = list(map(int, input().split()))

for A1, B1 in [(a1, b1), (b1, a1)]:
    for A2, B2 in [(a2, b2), (b2, a2)]:
        for A3, B3 in [(a3, b3), (b3, a3)]:
            if A2 + A3 <= A1 and max(B2, B3) <= B1:
                print("YES")
                exit()
print("NO")
