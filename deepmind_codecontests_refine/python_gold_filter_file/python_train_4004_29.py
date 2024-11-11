import math

def digit_sum(n):
    su = 0
    while n:
        su += (n % 10)
        n /= 10
        n = math.floor(n)
    return su

def main():
    a,b,c = [int(x) for x in input().split()]
    ans = []
    for i in range(1, 82):
        term = math.floor((b * math.pow(i, a)) + c)
        # print(term)
        if term < 1000000000 and term > 0 and digit_sum(term) == i:
            ans.append(str(term))
    length = len(ans)
    print(length)
    if length:
        print(" ".join(ans))

if __name__ == '__main__':
    main()
