'''input
56
'''
k = int(input())
for m in range(5, int(k**0.5)+1):
    if k % m == 0 and k//m >= 5:
        a = ["aeiou" + "a"*(m-5)]
        for _ in range(k//m-1):
            a.append(a[-1][-1] + a[-1][:-1])
        print(''.join(a))
        break
else:
    print(-1)
