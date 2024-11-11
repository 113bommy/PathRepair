s = int(input())
input_array = input()
list = [int(i) for i in input_array.split(" ")]

x = 2 + (list[2] ^ min(list))
print(x)
