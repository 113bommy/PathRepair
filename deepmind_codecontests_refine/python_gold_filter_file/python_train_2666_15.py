big_letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
max_n = 0
n = int(input())
a = input().split(" ")
for el in a:
    n = 0 
    for i in el: 
        if i in big_letters:
            n += 1
    if n > max_n:
        max_n = n
print(max_n)
    