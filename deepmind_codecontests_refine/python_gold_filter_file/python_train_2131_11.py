a = int(input())

for b in range(1, 17):
    if '8' in str(a + b):
        print(b)
        break