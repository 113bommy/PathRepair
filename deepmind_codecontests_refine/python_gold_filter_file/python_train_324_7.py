
input()
data = list(map(int, input().split()))
even = sorted((v for v in data if v % 2  == 0), key=lambda v: -v)
odd = sorted((v for v in data if v % 2  == 1), key=lambda v: -v)

n_even = len(even)
n_odd = len(odd)

if n_even == n_odd:
    print(0)
elif n_even > n_odd:
    print(sum(even[n_odd + 1:]))
else:
    print(sum(odd[n_even + 1:]))

