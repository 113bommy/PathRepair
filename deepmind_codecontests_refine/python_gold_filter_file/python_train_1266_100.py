def countRhombus(i):
    if i <= 1:
        return 1
    return 4*(i-1) + countRhombus(i-1)

n = int(input())
print(countRhombus(n))
