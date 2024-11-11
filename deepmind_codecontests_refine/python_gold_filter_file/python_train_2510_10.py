from math import sqrt
if __name__ == '__main__':
    n = int(input())
    i = 1
    count = 0
    if n == 1:
        print(1)
    else:
        while i <= sqrt(n):
            if n % i == 0:
                if n/i == i:
                    count += 1
                else:
                    count += 2
            i += 1
        print(count)
