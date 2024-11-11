A, B = [int(x) for x in input().split()]
print(A+B if (B%A == 0) else B-A)
