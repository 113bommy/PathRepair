t = int(input())

def solve():
    n = int(input())
    arr = list(map(int,input().split(" ")))
    s = sum(arr)
    prime = [True for i in range(s + 1)]
    p = 2
    while (p * p <= s):
         
        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
             
            # Update all multiples of p
            for i in range(p ** 2, s + 1, p):
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False

    if not prime[s]:
        print(n)
        print(*list(range(1,n+1)))
    else:
        k = 0
        for e in arr:
            if e%2:
                k = e
                break
        print(n-1)
        for i in range(n):
            e = arr[i]
            if e !=k:
                print(i+1,end=' ')
        print()
        



for i in range(t):
    solve()

    




        


