t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0;psum = 0;power = 0;

    while True:
        psum += 2**power
        power += 1
        stig = (psum*(psum+1))//2
        n -= stig
        if n >= 0:
            ans +=1
        else:
            break

    print(ans)
