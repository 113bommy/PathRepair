n = int(input())

for _ in range(n):
    num = int(input())
    arr = []
    for i in range(1,int(num**.5)+1):
        if i ** 2<=num:
            arr.append(i ** 2)
        if i ** 3<=num:
            arr.append(i ** 3)

    print(len(set(arr)))