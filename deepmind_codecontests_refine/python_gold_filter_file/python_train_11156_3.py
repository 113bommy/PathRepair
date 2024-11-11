def prime(n,primes):
    return primes[n]

def seive(n):
    primes = [True]*n
    for i in range(2,n):
        if primes[i]:
            j = 2
            while i*j < n:
                primes[i*j] = False
                j += 1

    primes[0] = False
    primes[1] = False

    return primes

def main():
    primes = seive(10**6+1)
    n = int(input())
    edges = []
    for i in range(n):
        if i == n-1:
            edges.append((n,1))
        else:
            edges.append((i+1,i+2))

    if not prime(len(edges),primes):
        found = False
        start = 1
        end = n-1
        for i in range((n//2)-1):
            edges.append((start,end))
            if prime(len(edges),primes):
                found = True
                break
            start += 1
            end -= 1

        if not found:
            edges.append((start,n))
            if prime(len(edges),primes):
                found = True

        if not found:
            print(-1)
            return

    print(len(edges))
    for i in edges:
        print(i[0],i[1])


main()
