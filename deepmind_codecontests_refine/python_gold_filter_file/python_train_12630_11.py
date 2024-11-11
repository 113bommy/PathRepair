
for _ in range(int(input())):
    n = int(input())
    n_even = sum(v[-1] in '02468' for v in input().split())
    print(('No', 'Yes')[n_even == n])
