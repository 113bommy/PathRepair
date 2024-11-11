(n, k) = [int(x) for x in input().split()]

s = set()

for i in range(k):
    input()
    s |= set(input().split())
    
print(n-len(s))
