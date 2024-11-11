A, B = [int(n) for n in input().split()]
print(A+B if B%A==0 else B-A)
