n, k = map(int, input().split())
a = list(map(int, input().split()))

i = 1
while (i*(i+1))//2 <= k:
    i += 1
    
i -= 1

k -= (i*(i+1))//2

print(a[(k-1)%i])