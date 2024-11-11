n = int(input())

br = False
for a in range(0, n + 1, 1234567):
    for b in range(0, n - a + 1, 123456):
        if (n - a - b) % 1234 == 0:
            print("YES")
            br = True
            break
    if br:
        break
else:
    print("NO")