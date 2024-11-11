n = int(input())

numbers = list(map(int, input().split(' ')))

#numbers = [7,2, 7, 3, 3, 1, 4]
numbers = sorted(numbers)

def find_sequences(numbers):
    count = [0] * 200001
    for i in numbers:
        count[i] += 1

    a = list()
    b = list()
    for i, e in enumerate(count):
        if e == 1:
            a.append(i)
        if e == 2:
            a.append(i)
            b.append(i)
        if e >= 3:
            print('No')
            return
    print("Yes")
    print(len(a))
    print(' '.join(map(str, a)))
    print(len(b))
    print(' '.join(map(str, b[::-1])))
    return






find_sequences(numbers)