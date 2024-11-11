s = input()
n = int(s)
for i in range(n):
    s = input()
    a = int(s)
    s = bin(a)
    cnt0 = s.count('0') - 1
    l = len(s) - 2
    if cnt0 > 0:
        print(2 ** l - 1)
    else:
        p = [2, 3, 5, 7, 13, 17, 19]
        if l in p:
            print(1)
        else:
            for i in range(3, a):
                if a % i == 0:
                    print(a // i)
                    break