n, k = tuple(map(int, input().split()))
s = input()
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'][: k]

count_array = []
for i in alphabet:
    count_array.append(s.count(i.upper()))
if count_array.count(0) != 0:
    print(0)
else:
    print(min(count_array) * k)
