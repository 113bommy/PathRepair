n, k = map(int, input().split())
ai = list(map(int, input().split()))
temp = max(ai)
temp2 = min(ai)
if temp - temp2 > k:
    print("NO")
else:
    print("YES")
    for i in ai:
        i2 = i // k
        i3 = i - i2 * k
        for i in range(k):
            if i2 > 0:
                print((str(i+1)+" ")*(i2),end="")
            else:
                break
        for i in range(k):
            if i3 > 0:
                print(i+1,end=" ")
            else:
                break
            i3 -= 1
        print()
