from math import sqrt

def main():
    def solve():

        n = int(input())
        a = 0
        if n%2 == 0:
            a = 2
        else:
            for i in range(3, int(n ** (1./3))+1, 2):
                if n%i == 0:
                    a = i
                    break
        if a == 0:
            print("NO")
            return
        b = 0
        for i in range(a+1, int(sqrt(n//a))+1):
            if (n//a)%i == 0:
                b = i
                break
        if b == 0:
            print("NO")
            return
        c = n//(a*b)
        if b == c:
            print("NO")
            return
        print("YES")
        print(a, b, c)



    q = int(input())
    for _ in range(q):
        solve()


if __name__ == "__main__":
    main()