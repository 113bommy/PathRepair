

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a = list(set(a))
    a.sort()
    m = len(a)
    res = 0
    if len(a) == 1:
        print('0')
        return
    if len(a) > 2:
        if (a[0] + a[m-1]) % 2 == 1:
            print('-1')
            return
        else:
            res = (a[0] + a[m-1])/2

            for i in range(1, m-1):
                if a[i] != res:
                    print('-1')
                    return
        print(int(res) - a[0])

    if len(a) == 2:
        if sum(a) % 2 == 1:
            res= a[m-1] - a[0]
        else:
            res= sum(a)/2 - a[0]
        print(int(res))
        
solve()
