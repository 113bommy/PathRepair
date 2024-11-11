kl=int(input())
for l in range(kl):
    n, s, k=[int(i) for i in input().split()]
    a=[int(i) for i in input().split()]
    for i in range(n):
        if max(1, s-i) not in a or min(n, s+i) not in a:
            print(i)
            break