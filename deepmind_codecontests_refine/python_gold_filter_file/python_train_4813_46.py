t = int(input())
for _  in range(t):
    a, b, c = map(int, input().split())
    ans = 10**18
    l = [a, b, c]
    for x in range(1, 2*b+1):
        i = 1
        temp1 = abs(x-a)
        while x*(i-1) <= 2*c:
            temp2 = temp1
            temp2 += abs(x*i-b)
            temp2 += min(c%(x*i), (x*i)-c%(x*i))
            if temp2 <= ans:
                ans = temp2
                if c%(x*i) <= (x*i)-c%(x*i):
                    l = [x, i*x, c-c%(x*i)]
                else:
                    l = [x, i*x, c+(x*i)-c%(x*i)]
            i += 1
    print(ans)
    print(*l)
