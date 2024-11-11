from re import fullmatch
s = input()
print("AC" if fullmatch("A[a-z]+C[a-z]+", s) is not None else "WA")