position = input()

if position[0] == 'a' or position[0] == 'h':
    if position[1] == '1' or position[1] == '8':
        print(3)
    else:
        print(5)
elif position[1] == '1' or position[1] == '8':
    print(5)
else:
    print(8)
