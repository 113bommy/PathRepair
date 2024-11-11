import sys
def input(): return sys.stdin.readline().rstrip()


def main():
    n = int(input())
    ans = 2-(n==2)
    for k in range(2,int(n**0.5)+1):
        if n % k == 1:
            ans += 2
            ans -=k**2+1==n
        elif n % k == 0:
            g = n//k
            while g % k == 0:
                g = g//k
            ans += g % k == 1
    
    print(ans)


if __name__ == '__main__':
    main()