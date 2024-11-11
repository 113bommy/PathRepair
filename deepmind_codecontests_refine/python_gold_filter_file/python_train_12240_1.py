[n, m, k] = [int(x) for x in input().split()]
print((((k+1)//2)+m-1)//m, ((k-1)//2)%m + 1, 'L' if k%2 == 1 else 'R')
