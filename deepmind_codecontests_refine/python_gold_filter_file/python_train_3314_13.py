from collections import Counter 

N, K = map(int, input().split())
A = list(map(int, input().split()))
s = len(set(A))
t = s-K

c = Counter(A)
num = list(c.values())
num.sort()

print(sum(num[:t])) if t>0 else print(0)