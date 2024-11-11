n = int(input())

def get_val(a, b):
    for i in range(10):
        x = (a >> i) % 2
        y = (b >> i) % 2
        if x != y:
            return (i + 1)

for i in range(1, n):
    print(*[get_val(i,j) for j in range(i + 1, n + 1)])
