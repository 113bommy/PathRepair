c = ['W','B']
n = int(input())

for i in range(n):
    for j in range(n):
        print(c[(i+j)%2],end="")
    print()