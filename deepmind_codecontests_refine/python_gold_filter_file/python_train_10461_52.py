k, n, w = [int(i) for i in input().strip().split()]

print(max(k*w*(w+1)//2-n, 0))