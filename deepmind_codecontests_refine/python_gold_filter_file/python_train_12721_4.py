import math

def main():
    q = int(input())
    for iter in range(q):
        n = int(input())
        log = int(math.log(n, 3))
        check = math.pow(3, log + 1)
        if (check - 1) / 2 < n:
            print(int(check))
        elif int((check - 1) / 2) == n:
            print(n)
        else:
            result = check / 3
            rest = n - result
            log -= 1
            while rest > 0:
                l = -1
                r = log
                while r - l > 1:
                    mid = int((r + l) / 2)
                    a = (math.pow(3, mid + 1) - 1) / 2
                    if a < rest: l = mid
                    else: r = mid
                result += math.pow(3, r)
                rest = n - result
                log = r - 1
            print(int(result))


    

main()