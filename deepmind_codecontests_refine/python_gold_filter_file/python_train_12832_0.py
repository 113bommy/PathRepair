import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [0] * (n + 1) 
        arr = [int(x) for x in input().split()]
        for x in arr:
            a[x] += 1
        
        res = 0
        for i in range(2, 2 * n + 1):
            c = 0
            for j in range(1, (i + 1) // 2):
                if i - j > n:
                    continue
                c += min(a[j], a[i - j])

            if i % 2 == 0:
                c += a[i // 2] // 2;
            res = max(res, c)

        print(res)

        

        