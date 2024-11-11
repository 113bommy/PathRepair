A, B, C, D = [int(x) for x in input().split()]
print("Yes" if abs(A-C) <= D or (abs(A-B)<=D and abs(B-C)<=D) else "No")