from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))

pf = [0]+list(accumulate(a))

q = int(input())

for _ in range(q):
    l, r = map(int, input().split())
    
    print((pf[r]-pf[l-1])//10)