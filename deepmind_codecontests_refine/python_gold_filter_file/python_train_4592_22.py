nb_test = int(input())
for _ in range(nb_test):
    a, b = [int(x) for x in input().split()]
    if a - b != 1:
        print("NO")
    else:
        ans = "YES"
        a += b
        i= 2
        while i * i <= a:
            if a % i == 0:
                ans = "NO"
                break
            i += 1
        print(ans)