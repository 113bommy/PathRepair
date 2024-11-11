from collections import defaultdict
 
def main():
    (n, k) = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    last = 0
    c = 1
    for ai in a:
        if ai == last:
            c += 1
        else:
            c = 1
        last = ai
    if c + k > n:
        return n - c
    else:
        return -1
 
print(main())