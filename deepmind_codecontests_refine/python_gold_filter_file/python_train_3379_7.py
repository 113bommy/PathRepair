n = int(input())

x = list(map(int, input().strip().split()))
y = list(map(int, input().strip().split()))

total = x[1:] + y[1:]

set_total = set(total)
# print(set_total)

if len(set_total) == n:
    print("I become the guy.")
elif len(set_total) < n:
    print("Oh, my keyboard!")