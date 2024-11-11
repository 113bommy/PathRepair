n = int(input())
xs = [int(i) for i in input().split()]
if n == 1:
    print(xs[0])
else:
    output1 = [None] * (n // 2)
    output2 = [None] * (n // 2)
    suf = 1
    if n % 2 == 1:
        suf = 2
    for i in range(n // 2):
        output1[i] = xs[i*2]
        if -(-2 * i - suf) <= n:
            output2[i] = xs[-2 * i - suf]
    if n % 2 == 1:
        output1.append(xs[n - 1])
        output1.reverse()
        output2.reverse()
        print(" ".join([str(i) for i in (output1 + output2)]))
    else:
        print(" ".join([str(i) for i in (output2 + output1)]))

