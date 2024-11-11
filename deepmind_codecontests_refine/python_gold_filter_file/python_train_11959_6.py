

while True:
    num = int(input())

    if num == 0: 
        break
    
    list = []
    for i in range(num):
        list.append(int(input()))

    for i in range(1, num):
        list[i] = max(list[i - 1] + list[i], list[i])

    print(max(list))