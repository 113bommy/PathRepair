from math import ceil
def main():
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
        
    s = a[0] // k
    next = a[0] % k
    if n == 1:
        print(ceil(a[0] / k))
        return 0
    
    for i in range(1, n-1):
        if (a[i] + next) % k:
            if a[i] + next < k:
                if next:
                    s += 1
                    next = 0
                else:
                    next = a[i]
            else:
                s += (a[i] + next) // k
                next = (a[i] + next) % k
        else:
            s +=  (a[i] + next) // k
            next = 0
    
    s += ceil((a[-1] + next) / k)
    print(s)
    
main()